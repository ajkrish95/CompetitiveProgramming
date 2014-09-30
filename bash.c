#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>


//Variable s used for storing the imput command line
char* s;
//dummy variable used to pass as an argument for the functions like wait() , waitpid()
int dummy;

//=========================================================================
//Structure to store the atomic commands
//---------------------------------------------------------------------
struct command {
	char* args[100];
	int redir,num; //redir 0 - input , 1 - output
};

//Constructor for the command structure
struct command* constructCommand(int r,int n){
	struct command* temp;
		temp = (struct command*)malloc(sizeof(struct command));
		temp->redir=r;
		temp->num=n;
	return temp;
}
//=========================================================================


//=========================================================================
//Struture Pipeline to store piped commands Ex: ls -l | grep a | wc
//-------------------------------------------------------------------------
struct pipeline{
	struct  command* cmd;
	struct pipeline* next;
};

//Constructor for piepline
struct pipeline* constructPipeLine(){
	struct pipeline* temp = (struct pipeline*)malloc(sizeof(struct pipeline));
		temp->cmd = 0;
		temp->next = 0;
	return temp;
}
//--------------------------------------------------------------------------

//===========================================================================
//Structure to store the list of commands Ex: ls ; cal | wc; date | grep 1 | wc ;
//---------------------------------------------------------------------------
struct listline{
	struct pipeline* ppline;
	struct listline* next;
	int flag;//0 - & , 1 - ;
};
//Constructor for the list line commands
struct listline* constructListLine(int f){
	struct listline* temp = (struct listline*)malloc(sizeof(struct listline));
		temp->ppline = 0;
		temp->next = 0;
		temp->flag =f;
	return temp;

}

//=========================================================================

//=========================================================================
//Structure to store the background jobs
//-------------------------------------------------------------------------
struct backgroundjob{
    int pid;
    char* cmd;
    struct backgroundjob* next;
};

struct backgroundjob* bjs;

//Constructor for background jobs
struct backgroundjob* constructBackgroundJob(int p,struct command* c){
    struct backgroundjob* b=(struct backgroundjob*)malloc(sizeof(struct backgroundjob));
    b->pid=p;
    b->cmd=strdup(c->args[0]);
return b;
}

//To insert into background jobs
void insertBackgroundJob(struct backgroundjob* b){

if(bjs==NULL){
    bjs=b;
    return;
}
    struct backgroundjob* temp=bjs;
    while(temp->next!=NULL){temp=temp->next;}
    temp->next=b;

}

//=========================================================================

//=========================================================================
//Functions for printing the listline , pipeline and command structures and backgroung jobs..
void printCommand(struct command* com){
    int i=0;
        for(i=0;i<com->num;i++){
            printf("%s\t",com->args[i]);
        }

}
void printPipeLine(struct pipeline* pipe){
    if(pipe){
        printCommand(pipe->cmd);
        printf("\t|\t");
        printPipeLine(pipe->next);
    }

}

void printListLine(struct listline* lis){
    if(lis){
        printPipeLine(lis->ppline);
        printf("\n%c\n",(lis->flag==1)?';':'&');
        printListLine(lis->next);
    }
}


void printBackgroundJobs(){
    struct backgroundjob* temp=bjs;
        while(temp){
            printf("\n\n%d - %s\n",temp->pid,temp->cmd);
            temp=temp->next;
        }
}

//=========================================================================


//=========================================================================
//Parsing functions for the given command line into listline , pipeline and command structures
//-------------------------------------------------------------------------

//Function getting atomic token from the string of input
char* getToken(){

    char buf[100];
    int i=0;
        while(*s==' ' || *s=='\t')s++;
            if(*s=='&' || *s==';' || *s=='|' || *s=='\0')
                return NULL;
            else
            if(*s == '>')
                {s++;return strdup(">");}
            else if(*s == '<')
                {s++;return strdup("<");}
            while(*s!=' ' && *s!='\t' && *s!='<' && *s!='>' && *s!='&' && *s!=';' && *s!='|' && *s!='\0' && *s!='\n'){
                buf[i++]=*s;
                s++;
            }
        buf[i]='\0';
    return strdup(buf);
}

//Function for getting the atomic command from the list of pipes that is input
struct command* Command(){
    struct command* temp = constructCommand(1,0);//args for two integers
    char* token = getToken();
        while(token){
            if(*token == '>')temp->redir=1;
            else if(*token == '<')temp->redir = 0;
                temp->args[temp->num]=token;
                (temp->num)++;
                token = getToken();
            }
        temp->args[temp->num]=0;
    return temp;
}

//Function for getting the list of pipes from the list of commands that are input
struct pipeline* pipeLine(){
    struct pipeline* pipe = constructPipeLine();
    struct command* temp = Command();
    pipe->cmd = temp;
        while(*s == '|'){
            s++;
            pipe->next = pipeLine();
        }
    return pipe;
}


//Function for getting the list with pipes inside of them from the input command line
struct listline* listLine(){
    struct listline* list = constructListLine(1); //put into constructlistline
    struct pipeline* temp = pipeLine();
        list->ppline = temp;
            while(*s == ';' || *s == '&' || *s=='\n' || *s=='\0'){
                    if(*s == '&'){
                        s++;
                        list->next = listLine();
                        list->flag = 0;
                    }else
                    if(*s == ';'){
                        s++;
                        list->next = listLine();
                        list->flag = 1;
                    }else{
                        break;
                    }
            }
        return list;
}

//Invocation of the parser with given input
struct listline* parseCommand(char* str){
    s= strdup(str);
        struct listline* temp = listLine(s);

    return temp;
}

//=========================================================================


//=========================================================================
//Execute the respective list line , pipelines and commands
//-------------------------------------------------------------------------
//Function to execute given atomic command by execvp
void executeCommand(struct command* cmd){
int i=0,fdw=-1,fdr=-1;
char* a[100];
    while(i<cmd->num && cmd->args[i][0]!='<'  && cmd->args[i][0]!='>' ){
        a[i]=cmd->args[i];
        i++;
    }

a[i]=0;
    while(i<cmd->num){
    if(cmd->args[i][0]=='>'){
        i++;
        fdw=open(cmd->args[i],O_APPEND | O_CREAT | O_WRONLY,S_IRUSR |S_IWUSR |S_IXUSR);
            if(fdw<0){
                    fprintf(stderr,"Problem opening file\n");
                    exit(0);
                }
        dup2(fdw,1);
    }else if(cmd->args[i][0] == '<'){
        i++;
        fdr=open(cmd->args[i],O_RDONLY);
            if(fdr<0){
                    fprintf(stderr,"Problem opening file\n");
                    exit(0);
                }
        dup2(fdr,0);
    }
    else{
        fprintf(stderr,"Invalid Redirection\n");
        exit(1);
    }
        i++;
    }
    if(strcmp(a[0],"lsb")==0){
    //print background jobs
        printBackgroundJobs();
        exit(-1);
    }else
        execvp(a[0],a);
//return fwd;
}


//Function for executing the piped commands while attaching output of former to the input of later via pipes
void executePipeLine(struct pipeline* p,int w){
    int pip[2];
    int pid;
        if(p->next==NULL){
            if((pid = fork())==0){
                executeCommand(p->cmd);
            }
            if(w==0)insertBackgroundJob(constructBackgroundJob(pid,p->cmd));

            if(w==1)waitpid(pid,&dummy,WUNTRACED);

        return;
        }
    pipe(pip);
    int p1,p2;

    if((p1=fork())==0){
        close(1);
        dup(pip[1]);
        close(pip[0]);
        close(pip[1]);
        executeCommand(p->cmd);

    }else
    if((p2=fork())==0){
        close(0);
        dup(pip[0]);
        close(pip[1]);
        close(pip[0]);
        executePipeLine(p->next,w);
        exit(0);
    }
    close(pip[0]);
    close(pip[1]);
    if(w==1)waitpid(p1,&dummy,WUNTRACED);
    if(w==1)waitpid(p2,&dummy,WUNTRACED);
    return;
}

//Function for executing given list of commands serially one after the other
void executeListLine(struct listline* list){

    if(list==NULL)return;
    if(list->ppline->cmd->num==0){return executeListLine(list->next);}

    if(strcmp(list->ppline->cmd->args[0],"cd")==0 && list->ppline->next==NULL){
        chdir(list->ppline->cmd->args[1]);
    }else
        executePipeLine(list->ppline,list->flag);

executeListLine(list->next);
}

//=========================================================================

//=========================================================================
//Print prompt and read commands from the dummy shell
//-------------------------------------------------------------------------
void printPrompt(void){
        printf("CS12B057 > ");
}

char* readLine(){
        char buf[1024];
        //fgets(buf,1024,stdin);
        //scanf("%[^\n]",buf);
        gets(buf);

    return strdup(buf);
}
//=========================================================================

//=========================================================================
//Functions to free the memory
//-------------------------------------------------------------------------
void free_command(struct command* c){
    int i=0;
        for(i=0;i<c->num;i++)
            free(c->args[i]);
    free(c);
}

void free_pipeline(struct pipeline* p){
    if(p==NULL)return;
        free_pipeline(p->next);
        free_command(p->cmd);
        free(p);
}

void free_listline(struct listline* l){
    if(l==NULL)return;
        free_listline(l->next);
        free_pipeline(l->ppline);
        free(l);
}

void removeBackgroundJob(struct backgroundjob* prev){
    if(prev==NULL){
        bjs=bjs->next;
        return;
    }
    prev->next=prev->next->next;
}
//=========================================================================


//=========================================================================
// Main Function : Slighty modified from given main to call rest of the functions in a loop
//-------------------------------------------------------------------------
int main(){
    char *cmdline;
    struct listline* list;

    while(1){

        struct backgroundjob* curr=bjs,*prev= NULL;
        while(curr != NULL){                                //Checking for the background processes wether completed or not
            if(waitpid(curr->pid, &dummy, WNOHANG)){
                fprintf(stderr,"Done : %d - %s\n",curr->pid,curr->cmd);
                removeBackgroundJob(prev);
             }
             prev = curr;
             curr = prev->next;
         }

        printPrompt();
        cmdline = readLine();           //Reading the command line
            if(strcmp(cmdline , "quit")==0)
                exit(1);
        list = parseCommand(cmdline);   // Invocation of parser
        //printListLine(list);
        executeListLine(list);          // Executing the given command

        free_listline(list);            // Free the allocated memory for storing the parsed commands
        free(cmdline);
    }
    return 0;
}
//=========================================================================
