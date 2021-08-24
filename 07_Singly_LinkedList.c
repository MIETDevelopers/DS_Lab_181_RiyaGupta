//A program to implement a Singly Linked List and develop functions to perform insertion, deletion and linear search operations.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
void insert();
void addatbeginning();
void addafternode();
int length();
void display();
void delete();

typedef struct Node node;
node *root = NULL;
int len;
int main()
{
    int ch;
    do
    {
    printf("Single linked list operation\n1->Insert a Node\n2->Add at the beginning\n3->Add after a Node\n");
    printf("4.Number of Nodes\n");
    printf("5.Display the list\n");
    printf("6.Delete a Node\n");
    printf("7.Exit the Program\n");
    printf("Enter your choice --> ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        insert();
        break;
    case 2:
        addatbeginning();
        break;
    case 3:
        addafternode();
        break;
    case 4:
        len=length();
        printf("There are %d Nodes\n",len);
        break;
    case 5:
        display();
        break;
    case 6:
        delete();
        break;
    case 7:
        exit(0);
        break;
    default:
        printf("INVALID CHOICE.....PLEASE TRY AGAIN");
    }
    printf("\n");    
    } while (ch!=7);
}
void insert()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter Node data --> ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        node *p;
        p=root;
        while (p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
    printf("\n");
}
void addatbeginning()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter node data --> ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
    printf("\n");
}
void addafternode()
{
    node *temp,*p;
    int loc,i=1,size;
    printf("Enter location --> ");
    scanf("%d",&loc);
    size=length();
    if (loc>size)
    {
        printf("INVALID LOCATION");
        printf("Currently list is having %d nodes",size);
    }
    else
    p=root;
    while (i<loc)
    {
        p=p->link;
        i++;
    }
    temp=(node*)malloc(sizeof(node));
    printf("Enter data to insert --> ");
    scanf("%d",&temp->data);
    temp->link=p->link;
    p->link=temp;
    printf("\n");
}
int length()
{
    int count=0;
    node*temp;
    temp=root;
    while (temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
    printf("\n");
}
void display()
{
    node*temp;
    temp=root;
    if (temp==NULL)
    {
        printf("No nodes in the list\n");
    }
    else
    {
       while (temp!=NULL)
       {
           printf("%d ",temp->data);
           temp=temp->link;
       }
    }
    printf("\n");   
}
void delete()
{
    node*temp;
    int loc;
    printf("Enter location to delete --> ");
    scanf("%d",&loc);
    if (loc>length())
    {
        printf("INVALID LOCATION\n");
    }
    else if (loc==1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        node*p,*q;
        p=root;
        int i=1;
        while (i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
    printf("\n");
    
    
}