//Program to implement a Queue using Linked List and develop functions to perform enqueue and dequeue operations.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *front = NULL;
NODE *rear = NULL;

void enqueue()
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data that you want to insert in the queue --> ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void display()
{
    NODE *temp;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = front;
        printf("The elements in the Queue are --> ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void dequeue()
{
    NODE *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("%d has been removed from the Queue\n", temp->data);
        front = front->next;
        free(temp);
    }
}
int main()
{
    int ch;
    do
    {
        printf("\"PLEASE SELECT ANY OF THE QUEUE OPERATION\"\n");
        printf("1.Insert an element in the Queue\n");
        printf("2.Delete an element from the Queue\n");
        printf("3.Display the element in the Queue\n");
        printf("4.Exit the Program\n");
        printf("Enter your choice --> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("WRONG CHOICE....PLEASE TRY AGAIN");
            break;
        }
        printf("\n\n");
    } while (ch!=4); 
    return 0;
}