//Program to implement a Stack using Array and develop functions to perform push and pop operations.
#include<stdio.h>
int stack[5];
int top=-1;
void push();
void pop();
void view();
int main()
{	
	int ch;
	while(ch!=4)
	{
	printf("\n1. Push\n");
	printf("2. Pop\n");
	printf("3. View\n");
	printf("4. Exit\n");
	printf("\nEnter your choice\n");
	scanf("%d",&ch);
		switch(ch)
		{	
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: view();
			break;
			case 4:
			default:
              printf("\nWrong Choice");
		}
	}
}	
	void push()
		{
		int x;
		if(top==5-1)
		{
		    printf("\nStack overflow");
		}
		else
			{
		   printf("\nEnter the value to push\n");
			scanf("%d",&x);
			top=top+1;
			stack[top]=x;		
			}
		}
		
	void pop()
	{
		if(top==-1)
		{
			printf("\nStack underflow");
		}
		else
			{
                top=top--;
		    	printf("\ndeleted value is %d",stack[top]);
		
			}
	}
	
	void view()
	{
		int n;
		if(top>=0)
			{
				printf("\nStack is\n");
				for(n=top;n>=0;n--)
				{
					printf("\n%d",stack[n]);
				}
			}
        else
        {
            printf("\nstack is empty");
        }        
	}