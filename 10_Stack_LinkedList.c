//A program to implement a Stack using Linked List and develop functions to perform push and pop operations.
#include <stdio.h>  
#include <stdlib.h>

void push();  
void pop();  
void display();  
int count=0;

struct node  
{  
        int val;  
        struct node *next;  
};  
struct node *head;
 
int main()
{
    int choice;
    while(1){
                printf("\n~Stack Operation using Singly Linked List~");
                printf("\n 1. Push a node.");
                printf("\n 2. Pop a node.");
                printf("\n 3. Display all nodes.");
                printf("\n 4. Exit the proggram.");
                printf("\n Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                            printf("\n~Implementing insert function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            push();
                            break;
                    case 2:
                            printf("\n~Implementing delete function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            pop();
                            break;
                    case 3:
                            printf("\n~Implementing display function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            display();
                            break;    
                    case 4:
                            printf("Exiting the program!");
                            exit(0);
                            break;
                    default:
                            printf("\nWrong Choice! :/");
                            break;
                }
        }
        return 0;
}
 
void push ()  
{  
    int val;  
    struct node ptr = (struct node)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOut of memory! :/");  
    }  
    else  
    {  
        printf("\nEnter the value: ");  
        scanf("%d",&val);  
        if(head==NULL)  
        {        
            ptr->val = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }  
        else  
        {  
            ptr->val = val;  
            ptr->next = head;  
            head=ptr;  
               
        }
        count++;
    }  
}  
 
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("\nUnderflow! :/");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);
        count--;
    }  
}

void display()  
{  
    int i;  
    struct node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("\nStack is empty! :/");  
    }  
    else  
    {  
        printf("\nNodes in stack are:");  
        while(ptr!=NULL)  
        {  
            printf(" %d,",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
}