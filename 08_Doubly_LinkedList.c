//A program to implement a Doubly Linked List and develop functions to perform insertion, deletion and linear search operations.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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
    printf("Single linked list operation\n");
    printf("1.Insert a Node\n");
    printf("2.Add at the beginning\n");
    printf("3.Add after a Node\n");
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
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        node *p;
        p=root;
        while (p->right!=NULL)
        {
            p=p->right;
        }
        p->right=temp;
        temp->left=p;
    }
    printf("\n");
}
void addatbeginning()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter node data --> ");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->right=root;
        root->left=temp;
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
    temp=(node*)malloc(sizeof(node));
    printf("Enter node data :");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    p=root;
    while (i<loc)
    {
        p=p->right;
        i++;
    }
    temp->right=p->right;
    p->right->left=temp;
    temp->left=p;
    p->right=temp;
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
        temp=temp->right;
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
           temp=temp->right;
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
        root=temp->right;
        temp->right=NULL;
        free(temp);
    }
    else
    {
        node*p,*q;
        p=root;
        int i=1;
        while (i<loc-1)
        {
            p=p->right;
            i++;
        }
        q=p->right;
        p->right=q->right;
        q->right=NULL;
        free(q);
    }
    printf("\n");
}