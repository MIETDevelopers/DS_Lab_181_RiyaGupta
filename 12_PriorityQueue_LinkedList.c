//A program to implement a Priority Queue using Linked List and develop functions to perform enqueue and dequeue operations.
#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void view();
int count=0;
typedef struct priorityqueue
{
	int data, pr;
	struct priorityqueue *next;
}node;
node *front=NULL;
node *rear=NULL;

int main()
{
	int choice;
    printf("Welcome\n");
    do
    {
        printf("Main Menu\n");
        printf("1.Enqueue the value in the Queue\n");
        printf("2.Dequeue the value from the Queue\n");
        printf("3.Display the Queue\n");
        printf("4.Exit the Program\n");
        printf("Enter your choice --> ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                view();
                break;  

            case 4:
                printf("Program Terminated\n");
                break;

            default:
                printf("Enter a valid input(1/2/3/4)"); 
        }
        printf("\n");
    }while(choice!=4);
}

void enqueue()
{
	int prior;
	node *ptr, *temp;
	ptr=(node*) malloc(sizeof(node));
	if (ptr==NULL)
	{
		printf("Oops! can't enqueue......Memory not available\n");
	}
	printf("Enter the element\n");
	scanf("%d",&ptr->data);
	printf("Enter the priority\n");
	scanf("%d",&prior);
	ptr->pr=prior;
	ptr->next=NULL;

	if (front==NULL)
	{
		front=ptr;
		rear=ptr;
		printf("%d enqueued with priority %d\n",ptr->data, ptr->pr);
		count++;
	}
	else if (front->pr > prior)
	{
		temp=front;
		front=ptr;
		ptr->next=temp;
		printf("%d enqueued with priority %d\n",ptr->data, ptr->pr);
		count++;
	}
	else
	{
		temp=front;
		while((temp->next!=NULL) && ((temp->next->pr) <= prior))
		{
			temp=temp->next;
		}
		ptr->next=temp->next;
		temp->next=ptr;
		printf("%d enqueued with priority %d\n",ptr->data, ptr->pr);
		count++;
	}
	printf("Total elements=%d\n",count);
    printf("front=%d\n",front->data);
    printf("rear=%d\n",rear->data);
}	

void dequeue()
{
	node *temp;
	if (front==NULL && rear==NULL)
    {
        printf("Oops! can't dequeue.....Queue is empty\n");
    }
    else
    {
    	temp=front;
    	front=front->next;
    	printf("%d dequeued with priority %d\n",temp->data, temp->pr);
    	count--;
    }
    printf("Total elements=%d\n",count);
    printf("front=%d\n",front->data);
    printf("rear=%d\n",rear->data);
}

void view()
{
    node *temp;
    if (front==NULL && rear==NULL)
    {
        printf("Oops! can't dequeue.....Queue is empty\n");
    }
    else
    {
        temp=front;
        while(temp!=NULL)
        {
            printf("%d with priority %d\t",temp->data, temp->pr);
            printf("\n");
            temp=temp->next;
        }
        printf("\nTotal elements=%d\n",count);
        printf("front=%d\n",front->data);
        printf("rear=%d\n",rear->data);
    }
}