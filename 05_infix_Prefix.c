//Program to convert an infix expression to its corresponding prefix expressions.
#include <stdio.h>  
 #include <stdlib.h>  
 #include <math.h>  
 #include <string.h>  
 #define MAX 100  
 #define TAB '\t'  
 #define BLANK ' '  
 int top = -1;  
 void push(long int symbol);  
 long int pop();  
 void infix_to_postfix();  
 long int eval_post();  
 int priority(char symbol);  
 int isEmpty();  
 int white_space(char symbol);  
 char infix[MAX], postfix[MAX];  
 long int stack[MAX];  
 char *reverses(char str[]);  
 char str_tmp[100];  
 long long int count = 0;  
 int main()  
 {  
   long int value;  
   top = -1;  
   printf("Enter the infix:"); //enter the whole expression here  
   gets(infix);  
   strcpy(infix, reverses(infix));//Here we reverse the expression  
   infix_to_postfix(); //calling function  
   printf("Prefix:%s\n", reverses(postfix));  
   value = eval_post();  
   printf("Value of expression: %ld\n", value);  
 }  
 void infix_to_postfix()  
 {  
   unsigned int i, p = 0;  
   char next;  
   char symbol;  
   for (i = 0; i < strlen(infix); i++)  
   {  
     symbol = infix[i]; //assigning each value of infix expression to symbol  
     if (!white_space(symbol))  
     {  
       switch (symbol)  
       {  
       case '(':  
         push(symbol);  
         break;  
       case ')':  
         while ((next = pop()) != '(')  
         {  
           postfix[p++] = next;  
         }  
         break;  
       case '+':  
       case '-':  
       case '*':  
       case '/':  
       case '%':  
       case '^':  
         while ((!isEmpty()) && (priority(stack[top]) > priority(symbol)))  
         {  
           postfix[p++] = pop();  
         }  
         push(symbol);  
         break;  
       default:  
         postfix[p++] = symbol;  
       }  
     }  
   }  
   while (!isEmpty()) //if some symbols remains left they are pop out here  
   {  
     postfix[p++] = pop();  
   }  
   postfix[p] = '\0'; //the expression in string format  
 }  
 char *reverses(char str[])//it reverse the string  
 {  
   int len = strlen(str);  
   int j = 0;  
   for (int i = len - 1; i >= 0; i--)  
   {  
     if (str[i] == '(')  
     {  
       str_tmp[j] = ')';  
       j++;  
     }  
     else if (str[i] == ')')  
     {  
       str_tmp[j] = '(';  
       j++;  
     }  
     else  
     {  
       str_tmp[j] = str[i];  
       j++;  
     }  
   }  
   str_tmp[j++] = '\0';  
   return str_tmp;  
 }  
 int priority(char symbol)//it assign the priority to the operators  
 {  
   switch (symbol)  
   {  
   case '(':  
     return 0;  
     break;  
   case '+':  
   case '-':  
     return 1;  
     break;  
   case '*':  
   case '/':  
   case '%':  
     return 2;  
     break;  
   case '^':  
     return 3;  
     break;  
   default:  
     return 0;  
   }  
 }  
 void push(long int symbol)  
 {  
   if (top > MAX)  
   {  
     printf("Stack overflow");  
     return;  
   }  
   top = top + 1;  
   stack[top] = symbol;  
   count++;  
 }  
 long int pop()  
 {  
   if (isEmpty())  
   {  
     printf("Stack underflow\n");  
     return 0;  
   }  
   return stack[top--];  
 }  
 int isEmpty()  
 {  
   if (top == -1)  
   {  
     return 1;  
   }  
   else  
   {  
     return 0;  
   }  
 }  
 int white_space(char symbol)  
 {  
   if (symbol == BLANK || symbol == TAB)  
   {  
     return 1;  
   }  
   else  
     return 0;  
 }  
 long int eval_post()//this function is for the evaluation of the expression  
 {  
   long int a, b, temp, result;  
   unsigned int i;  
   for (i = 0; i < strlen(postfix); i++)  
   {  
     if (postfix[i] <= '9' && postfix[i] >= '0')  
     {  
       push(postfix[i] - '0'); //conversion of string format to numeric for calcultion  
     }  
     else  
     {  
       a = pop();  
       b = pop();  
       switch (postfix[i])  
       {  
       case '+':  
         temp = a + b;  
         break;  
       case '-':  
         temp = a-b;  
         break;  
       case '*':  
         temp = b * a;  
         break;  
       case '/':  
         temp = a/b;  
         break;  
       case '%':  
         temp = b% a;  
         break;  
       case '^':  
         temp = pow(a, b);  
         break;  
       }  
       push(temp);  
     }  
   }  
   result = pop();  
   return result;  
 }