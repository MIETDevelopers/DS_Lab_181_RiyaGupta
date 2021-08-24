//A program to check if a given expression is correctly parenthesized using Stacks.
#include<stdio.h> 
#include<conio.h>
int top=-1;      
int i;             
char Stack[50];                         
void push(char str)
{
      Stack[top] = str;
      top++;
}
                     
void pop()
{
      if (top == -1) 
      {
            printf("Unbalanced parenthesis, Please enter opening bracket\n");
      }
      else
      {
            top--;
      }
}
int main() 
{
      int opt;             
      char str[50];
      do{
	  printf("\nPLEASE SELECT ANY OF THE BELOW OPTIONS\n");
      printf("1.Check the Parenthesis of the expression\n");
      printf("2.Exit the Program\n");
      printf("Enter your choice");
      scanf("%d",&opt);
            switch (opt)
            {
                  case 1:
                        printf("\nEnter expression:");
                        scanf("%s",str);
                        printf("\nPress any key to continue\n");
                        getch();
                        for (i = 0; str[i] != '\0';i++) 
                        {
                              if (str[i] == '(' || str[i]=='[' || str[i]=='{')
                              {
                                    push(str[i]);
                              }
                              else if (str[i] == ')' || str[i]==']' || str[i]=='}')
                              {
                                    pop();
                              }
                        }
                       if(top==-1) 
					    {
               			 printf("Entered expression has balanced parenthesis\n");
        				}
        else
        	{
                printf("Entered expression does not has balanced parenthesis\n");
				break; 
                  case 2:
                  	printf("Exiting program\n");
                  	break;
                  default:
					printf("\nWrong choice\n");
            }
      }
      printf("\n\n");
      }while(opt!=2);
      return 0;
}