#include <iostream>
#include <process.h> //for exit(1)
#include <conio.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

class BST{
    public:
    node *tree;
    BST(){
        tree=NULL;
    }
    void createTree(node **,int item);    //For Building Treevoid preOrder(node *);     //For Tree Traversalvoid inOrder(node *);
    void postOrder(node *);

    void determineHeight(node *,int *);
    int totalNodes(node *);
    int internalNodes(node *); //no. of non-leaf nodesint externalNodes(node *); //no. of leaf nodes.void removeTree(node **); //Remove tree from memory.

    node **searchElement(node **,int);
    void findSmallestNode(node *);
    void findLargestNode(node *);
    void deleteNode(int);
};


//it is used for inseting an single element in//a tree, but if calls more than once will create tree.void BST :: createTree(node **tree,int item){
    if(*tree == NULL){
        *tree = new node;
        (*tree)->data = item;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else{
        if( (*tree)->data > item)
            createTree( &((*tree)->left),item);
        else
            createTree( &((*tree)->right),item);
    }
}


void BST :: preOrder(node *tree){
    if( tree!=NULL){
        cout<<"   "<< tree->data;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void BST :: inOrder(node *tree){
    if( tree!=NULL){
        inOrder( tree->left);
        cout<<"   "<< tree->data;
        inOrder(tree->right);
    }
}


void BST :: postOrder(node *tree){
    if( tree!=NULL){
        postOrder( tree->left);
        postOrder( tree->right);
        cout<<"   "<<tree->data;
    }
}


void BST :: determineHeight(node *tree, int *height){
    int left_height, right_height;
    if( tree == NULL)
        *height = 0;
    else{
        determineHeight(tree->left, &left_height);
        determineHeight(tree->right, &right_height);
        if( left_height > right_height)
            *height = left_height + 1;
        else
            *height = right_height + 1;
    }
}


int BST :: totalNodes(node *tree){
    if( tree == NULL)
        return 0;
    elsereturn( totalNodes(tree->left) + totalNodes(tree->right) + 1 );
}

int BST :: internalNodes(node *tree){
    if( (tree==NULL)  || (tree->left==NULL  && tree->right==NULL))
        return 0;
    elsereturn( internalNodes(tree->left) + internalNodes(tree->right) + 1 );
}

int BST :: externalNodes(node *tree){
    if( tree==NULL )
        return 0;
    elseif( tree->left==NULL  && tree->right==NULL)
        return 1;
    elsereturn( externalNodes(tree->left) + externalNodes(tree->right));
}

void BST :: removeTree(node **tree){
    if( (*tree) != NULL){
        removeTree( &(*tree)->left );
        removeTree( &(*tree)->right );
        delete( *tree );
    }
}

node ** BST :: searchElement(node **tree, int item){
    if( ((*tree)->data == item) || ( (*tree) == NULL) )
        return tree;
    elseif( item < (*tree)->data)
        return searchElement( &(*tree)->left, item);
    elsereturn searchElement( &(*tree)->right, item);
}

void BST :: findSmallestNode(node *tree){
    if( tree==NULL || tree->left==NULL)
        cout<< tree->data;
    else
        findSmallestNode( tree->left);
}


//Finding In_order Successor of given node..//for Delete Algo.
node * find_Insucc(node *curr)
{
    node *succ=curr->right; //Move to the right sub-tree.if(succ!=NULL){
        while(succ->left!=NULL)    //If right sub-tree is not empty.
            succ=succ->left; //move to the left-most end.
    }
    return(succ);
}


void BST :: findLargestNode(node *tree){
    if( tree==NULL || tree->right==NULL)
        cout<<tree->data;
    else
        findLargestNode(tree->right);
}


void BST :: deleteNode(int item){
    node *curr=tree,*succ,*pred;
    int flag=0,delcase;
    //step to find location of nodewhile(curr!=NULL && flag!=1)
    {
        if(item < curr->data){
            pred = curr;
            curr = curr->left;
        }
        elseif(item > curr->data){
            pred = curr;
            curr = curr->right;
        }
        else{ //curr->data = item
            flag=1;
        }
    }

    if(flag==0){
        cout<<"\nItem does not exist : No deletion\n";
        getch();
        goto end;
    }

    //Decide the  case of deletionif(curr->left==NULL && curr->right==NULL)
        delcase=1; //Node has no childelseif(curr->left!=NULL && curr->right!=NULL)
        delcase=3; //Node contains both the childelse
        delcase=2; //Node contains only one child//Deletion Case 1if(delcase==1){
        if(pred->left == curr) //if the node is a left child
            pred->left=NULL; //set pointer of its parentelse
            pred->right=NULL;
        delete(curr); //Return deleted node to the memory bank.
    }

    //Deletion Case 2if(delcase==2){
        if(pred->left==curr){ //if the node is a left childif(curr->left==NULL)
                pred->left=curr->right;
            else
                pred->left=curr->left;
        }
        else{ //pred->right=currif(curr->left==NULL)
                pred->right=curr->right;
            else
                pred->right=curr->left;
        }
        delete(curr);
    }

    //Deletion case 3if(delcase==3){
        succ = find_Insucc(curr); //Find the in_order successor//of the node.int item1 = succ->data;
        deleteNode(item1);  //Delete the inorder successor
        curr->data = item1; //Replace the data with the data of//in order successor.
    }
end:
}



void main(){
    BST obj;
    int choice;
    int height=0,total=0,n,item;
    node **tmp;

    while(1){
        clrscr();
        cout<<"*****BINARY SEARCH TREE OPERATIONS*****\n\n";
        cout<<"--Binary Tree and Binary Search Tree common operations--\n";
        cout<<"1) Create Tree\n";
        cout<<"2) Traversal\n";
        cout<<"3) Height of Tree\n";
        cout<<"4) Total Nodes\n";
        cout<<"5) Internal Nodes \n";
        cout<<"6) External Nodes \n";
        cout<<"7) Remove Tree\n";
        cout<<"\n--Only Binary Search Tree Operations--\n";
        cout<<"8)  Insert Node\n";
        cout<<"9)  Search Node\n";
        cout<<"10) Find Smallest Node\n";
        cout<<"11) Find Largest Node\n";
        cout<<"12) Delete Node\n";
        cout<<"13) Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1 : //Create Tree
                cout<<"\n\n--Creating Tree--";
                cout<<"\nHow many nodes u want to enter : ";
                cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"Enter value : ";
                    cin>>item;
                    obj.createTree(&obj.tree,item);
                }
                break;

            case 2 : //All Traversals
                cout<<"\n\nInorder Traversal : ";
                obj.inOrder(obj.tree);

                cout<<"\n\nPre-order Traversal : ";
                obj.preOrder(obj.tree);

                cout<<"\n\nPost-order Traversal : ";
                obj.postOrder(obj.tree);
                getch();
                break;

            case 3 : //Determining Height of Tree
                obj.determineHeight(obj.tree,&height);
                cout<<"\n\nHeight of Tree : "<<height;
                getch();
                break;

            case 4 : //Total nodes in a tree
                total=obj.totalNodes(obj.tree);
                cout<<"\n\nTotal Nodes : "<<total;
                getch();
                break;

            case 5 : //Internal nodes in a tree
                total=obj.internalNodes(obj.tree);
                cout<<"\n\nInternal Nodes : "<<total;
                getch();
                break;

            case 6 : //External nodes in a tree
                total=obj.externalNodes(obj.tree);
                cout<<"\n\nExternal Nodes : "<<total;
                getch();
                break;

            case 7 : //Remove Tree from memory
                obj.removeTree(&obj.tree);
                cout<<"\n\nTree is removed from Memory";
                getch();
                break;

            case 8 : //Inserting a node in a tree
                cout<<"\n\n--Inserting Node in a tree--\n";
                cout<<"Enter value : ";
                cin>>item;
                obj.createTree(&obj.tree,item);
                cout<<"\nItem is inserted\n";
                getch();
                break;

            case 9 : //Search element
                cout<<"\n\n--Search Element--\n";
                cout<<"Enter item to searched : ";
                cin>>item;
                &(*tmp) = obj.searchElement(&obj.tree,item);
                if( (*tmp) == NULL)
                    cout<<"\nSearch Element Not Found";
                else
                    cout<<"\nSearch Element was Found";
                getch();
                break;

            case 10 : //Find Smallest Node
                cout<<"\n\nSmallest Node is :  ";
                obj.findSmallestNode(obj.tree);
                getch();
                break;

            case 11 : //Find Largest Node
                cout<<"\n\nLargest Node is :  ";
                obj.findLargestNode(obj.tree);
                getch();
                break;

            case 12 : //Deleting a node from a tree
                cout<<"\n\n--Deleting a Node from a tree--\n";
                cout<<"Enter value : ";
                cin>>item;
                obj.deleteNode(item);
                break;

            case 13 : exit(1);
        }//end of switch
    }
}
