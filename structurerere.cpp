#include<stdio.h>
#include<malloc.h>

using namespace std;
class dummy
{
	public:
	int c;
	char ch;
	
	
	//	dummy()
	//	{
			printf("hiya\n");
		}

		dummy(int a)
		{
			printf("hiya\n");
		}

		~dummy()
		{
			printf("Destructor");
		}
		
};


//typedef struct dummy dummy;

int count()
{
	static int a = 10;
	a++;
	printf("%d\n",a);
	 //dummy dum;
}
int main()
{	
	//dummy o(10);
	dummy* p = new dummy();

	p = (dummy*)malloc(sizeof(dummy));
	p->c = 1;
	//delete(p);

}
