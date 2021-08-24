//A program to implement a Queue using Array and develop functions to perform enqueue and dequeue operations.
#include <stdio.h>
#include<stdlib.h>
#define MAX 100
 
void insert();
void delete();
void display();
int Queue1[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int ch;
    while(1)
    {    
        printf("Choose your operation \n ----- \n");
        printf("1.Insert element to queue. \n");
        printf("2.Delete element from queue. \n");
        printf("3.Display all elements of queue. \n");
        printf("4.Quit. \n");
        printf(" ----- \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Wrong choice \n");
        }
    }
return 0;
}
 
void insert()
{
    int InputVal1;
    if (rear == MAX - 1)
    printf("Queue is Overflowing! \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("\nEnter value to insert in queue: ");
        scanf("%d", &InputVal1);
        rear = rear + 1;
        Queue1[rear] = InputVal1;
    }
}
 
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue is underflowing! \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", Queue1[front]);
        front = front + 1;
    }
}
 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty! \n");
    else
    {
        printf("Elements in queue are: ");
        for (i = front; i <= rear; i++)
            printf("%d ", Queue1[i]);
        printf("\n");
    }
}