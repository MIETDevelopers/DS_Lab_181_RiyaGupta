//A C program to find the cheapest walnut.
#include<stdio.h>
#include<string.h>
#include<stdlib.h> //Including header files

struct info
{
int item0;
char name[50];
int price;
struct info *next;
};
struct info *temp,*disp,*head; //user defined data type using structure 

int catSearch;

void addrecord();
void display();
void displaymin();
void displaymax();
void deleterecord();
void displaySpecMin();
void displaySpecMax(); //Declaring user defined functions

int main()
{
  int ch, ch1;
  while (1) //Using loop 
    {
      printf("\n~Dry Fruit tracker~\n");
      printf("\n 1. To add records.");
      printf("\n 2. To delete records.");
      printf("\n 3. To view the records.");
      printf("\n 4. To exit.");
      printf("\n Enter your choice: ");
      //Printing functions 
      
      scanf("%d",&ch);
      //Scaning input       
      
      fflush(stdin);
      switch(ch)
            {
              case 1:
                  addrecord();
                      break;

              case 2:
                  deleterecord();
                    break;
              
              case 3:
                  printf("\n 1. Display whole list.");
                  printf("\n 2. Display minimum priced item.");
                  printf("\n 3. Display maximum priced item.");
                  printf("\n 4. Display minimum price of Walnuts.");
                  printf("\n 5. Display maximum price of Walnuts.");
                  printf("\n 6. Display minimum price of Almonds.");
                  printf("\n 7. Display maximum price of Almonds.");
                  printf("\n 8. Display minimum price of Cashew.");
                  printf("\n 9. Display maximum price of Cashew.");
                  printf("\n10. Display minimum price of Peanut.");
                  printf("\n11. Display maximum price of Peanut.");
                  printf("\n Enter desired display option: ");
                  scanf("%d", &ch1);
                  switch(ch1)
                  {
                    case 1:
                      display();
                        break;

                    case 2:
                      displaymin();
                        break;

                    case 3:
                      displaymax();
                        break;

                    case 4: 
                      catSearch = 1;
                      displaySpecMin(catSearch);
                      break;

                    case 5:
                      catSearch = 1;
                      displaySpecMax(catSearch);
                      break;

                    case 6: 
                      catSearch = 2;
                      displaySpecMin(catSearch);
                      break;

                    case 7:
                      catSearch = 2;
                      displaySpecMax(catSearch);
                      break;

                    case 8: 
                      catSearch = 3;
                      displaySpecMin(catSearch);
                      break;

                    case 9:
                      catSearch = 3;
                      displaySpecMax(catSearch);
                      break;

                    case 10: 
                      catSearch = 4;
                      displaySpecMin(catSearch);
                      break;

                    case 11:
                      catSearch = 4;
                      displaySpecMax(catSearch);
                      break;

                    default:
                      printf("\n Wrong choice! :/");
                        break;
                  }
                      break;

              case 4:
                  exit(0);
                      break;

              default:
                  printf("Wrong choice! :/");
                    break;
            }
//Switch case is used to determine the function to be performed as per user input.

    }
return 0;
}

//body of declared functions.
void addrecord()
{
  struct info *add;
  //pointer variable created.
  
  add=(struct info*)malloc(sizeof(struct info));
  //Memory is allocated to variable using malloc.

  printf("\n Enter the name of dealer: ");
  gets(add->name);
  //gets to read string & assign to variable.
  printf("\n Enter the price of item: ");
  scanf("%d",&add->price);
  //scanf is used to read number & assign to variable.

  printf("\nWhich item's record you want to store?\n Available categories:");
  printf("\n1. Walnut\n2. Almond\n3. Cashew\n4. Peanut\n Enter your choice: ");
  scanf("%d", &add->item0);
  //This will assign an integer respective to the type of dry fruit.
  
  fflush(stdin);

    if(head==NULL|| head->price>=add->price)
      {
        add->next=head;
        head=add;
      }
    else
      {
        temp=head;
          
          while(temp->next!=NULL && temp->next->price < add->price)
            {
              temp=temp->next;
            }
//A loop is used so that it can iterate through whole list and place the data entered in ascending order with respect to price.
        add->next=temp->next;
        temp->next=add;
      }

//if-else statements are used to insert/add the user input into the list.
  return;
 }

void display()
{
  int count=0, category;
//A integer value is declared for printing serial number.
  if(head==NULL)
    {
      printf("\n No records to view\n");
      return;
    }
//If it is observed that the list is empty than the program will display the print statement & return back to main function.

  for(disp=head;disp!=NULL;disp=disp->next)
    {
      printf("\n -- \nSerial number: %d", count);
      printf("\nName of dealer: %s",disp->name);
      category=disp->item0;
      switch(category)
      {
        case 1: printf("\nCategory of item: Walnut"); 
                break;

        case 2: printf("\nCategory of item: Almond");
                break;

        case 3: printf("\nCategory of item: Cashew");
                break;

        case 4: printf("\nCategory of item: Peanut");
                break; 
      } //This switch case will determine the item type and print the respective name of item.
      printf("\nPrice of item: %d \n",disp->price);
      count++;
      //This will keep on increasing the value of interger by 1 each time the loop iterates.
    }
//The loop will iterate through whole list & keep on printing untill it reaches to the end of list.
  count=0;
//The variable declared would get initialed by zero.
return;
}

void deleterecord()
{
    display();
//The purpose of display function used here is to display user all the records then he can have precise information of record to be deleted.
    int i,pos;
    struct info *temp,*ptr;
    if(head==NULL)
    {
        printf("\nThe List is Empty! :/");
        return;
    }
//If it is observed that the list is empty than the program will display the print statement & return back to main function.
    else
    {
        printf("\nEnter the serial number of record to be deleted: ");
        scanf("%d",&pos);
            if(pos==0)
            {
                ptr=head;
                head=head->next;
                printf("\nRecord deleted!");
                    free(ptr);
            }
            else
            {
                ptr=head;
                for(i=0;i<pos;i++) 
                { 
                    temp=ptr; 
                    ptr=ptr->next;
                    if(ptr==NULL)
                    {
                        printf("\nNode not found :/");
                        return;
                    }
                }
                temp->next=ptr->next;
                printf("\nRecord deleted!");
                    free(ptr);
            }
    }
//if-else statements are used to delete the record from the list based on user input.
}

void displaymin()
{
  int category;
  if(head==NULL)
    {
      printf("\n No records to view!\n");
      return;
    }
//If it is observed that the list is empty than the program will display the print statement & return back to main function.

  for(disp=head;disp!=NULL;disp=disp->next)
    {
      if(disp=head)
      {
        printf("\nName of dealer: %s",disp->name);
        category=disp->item0;
        switch(category)
        {
          case 1: printf("\nCategory of item: Walnut"); 
                  break;

          case 2: printf("\nCategory of item: Almond");
                  break;

          case 3: printf("\nCategory of item: Cashew");
                  break;

          case 4: printf("\nCategory of item: Peanut");
                  break;
        }
        printf("\nPrice of item: %d \n",disp->price); 
        return; 
      }
    }
//The loop will iterate through whole list & will print the first element from loop as it will has minimum numeric value(price) in whole list.
return;  
}

void displaymax()
{
  int count1=0, count2=0,category;
  //Two variables are declared to used as counter
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    count1++;
  }
//A counter variable count1 is iterated in loop to get its value as the number of elements in list.

  for(disp=head;disp!=NULL;disp=disp->next)
  {
    count2++;
    //A counter variable count2 is iterated in loop to get its value increased by 1 each time it iterates.
    if(count1==count2)
    {
    printf("\nName of dealer: %s",disp->name);
    category=disp->item0;
    switch(category)
    {
      case 1: printf("\nCategory of item: Walnut"); 
              break;

      case 2: printf("\nCategory of item: Almond");
              break;

      case 3: printf("\nCategory of item: Cashew");
              break;

      case 4: printf("\nCategory of item: Peanut");
              break;
    }
    printf("\nPrice of item: %d \n",disp->price);
    return;
    }
    //If statement is used to check whether if both the counter variables are equal, if it does then it is determined that the loop has reached the end and it will print the record.
  }
    count1=0;
    count2=0;
}

void displaySpecMin()
{
  int count3=0;
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    if(catSearch==disp->item0) //This if statement will statisfy the need as per user input for query & will print specific output.
    {
      count3++;
      printf("\nName of dealer: %s",disp->name);
      printf("\nPrice of item: %d \n",disp->price);
      return; //This return statement is supposed to allow the loop to return to main function after t came into being.
    }
  }
    if(count3==0) //This if statement will work only if value of count3 is equal to 0, which can be possible if there no specific item present in list.
    {
      printf("\n No records to view!\n");
      return;
    }
}

void displaySpecMax()
{
  int count1=0, count2=0,category;
  //Two variables are declared to used as counter
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    if(disp->item0==catSearch)
    {
      count1++;
    }
    //A counter variable count1 is iterated in loop within if-else to get its value increased by 1 each time it iterates with satisfied.
  }
//A counter variable count1 is iterated in loop to get its value as the number of elements in list.

  for(disp=head;disp!=NULL;disp=disp->next)
  {
    if(disp->item0==catSearch)
    {
      count2++;
    }
    //A counter variable count2 is iterated in loop within if-else to get its value increased by 1 each time it iterates with satisfied.
    if(count1==count2)
    {
    printf("\nName of dealer: %s",disp->name);
    printf("\nPrice of item: %d \n",disp->price);
    return;
    }
    //If statement is used to check whether if both the counter variables are equal, if it does then it is determined that the loop has reached the end and it will print the record.
  }
      if(count1==0)
      {
        printf("\n No records to view!\n");
        return;
      }
    count1=0;
    count2=0; 
    //Initializing both values at 0 again.
}