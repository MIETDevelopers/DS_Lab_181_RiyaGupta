//A program to implement a Circular Linked List and develop functions to perform insertion, deletion and linear search operations.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *new, *head, *tail, *temp;

void insert()
{
    new = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data --> ");
    scanf("%d", &new->data);
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
        tail = new;
    }
    else
    {
        tail->next = new;
        tail = new;
        tail->next = head;
    }
}
void display()
{
    temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}
void deletefrombeginning()
{
    temp = head;
    head = head->next;
    tail->next = head;
    temp->next = NULL;
    free(temp);
}

int main()
{
    int ch;
    do
    {
        printf("\"PLEASE SELECT ANY OPTION BELOW\n\"");
        printf("1.Insert an Element in the Node\n");
        printf("2.Delete an element\n");
        printf("3.Display the list\n");
        printf("4.Exit the Program\n");
        printf("Enter your choice --> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            deletefrombeginning();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong Choice...... Please try again\n");
            break;
        }
        printf("\n\n");
    } while (ch != 4);
    return 0;
}