//A program to evaluate postfix, prefix and infix expressions using Stacks
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define high 12

//Infix function prototypes
void infix();
void pushOperand(float);
void pushOperator(char);
float popOperand();
int popOperator();
int precedence(char);
//Infix global variables
float operand[high]; 
int topOperand=-1, topOperator=-1, precedenceTop2=0;
char operator[high];

//Postfix function prototypes
void postfix();
void pushPostfix(float);
float popPostfix();
//Postfix global variables
float postStack[high];
int topPost = -1;
char post[high], *e;

//Prefix function prototypes
void prefix();
void pushPrefix(float);
float popPrefix();
//Prefix global variables
int topPre=-1;
float preStack[high], val;

//Main function
int main(){
    int choice=0;
    while (choice!=4){
        printf("Enter an option from the menu:\n");\
        printf("1 for Infix evaluation\n2 for Postfix evaluation\n");
        printf("3 for Prefix evaluation\n4 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            infix();
            break;
        case 2:
            postfix();
            break;
        case 3:
            prefix();
            break;
        case 4:
            printf("Thanks!");
            exit(0);
        default:
            printf("Incorrect option!\n");
            break;
        }
    }
}

//Infix function definitions
void infix(){
    int number;
    float num1, num2, result;
    char inf[high], ch, op;
    printf("Enter an infix expression: ");
    scanf("%s", &inf);
    printf("You entered: %s\n", inf);
    for(int i=0; inf[i]!='\0'; i++){
        ch=inf[i];
        if(isdigit(ch)){
            number = ch-'0';
            pushOperand(number);
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
            pushOperator(ch);
        else{
        printf("Undefined character!\n", ch);
        exit(0);
        }
    }
    for(int j=topOperator; j>=0; j--){
        op=popOperator();
        num1=popOperand();
        num2=popOperand();
        switch (op){
        case '+':
            result = num1+num2;
            break;
        case '-':
            result = num2-num1;
            break;
        case '*':
            result = num1*num2;
            break;
        case '/':
            result = num2/num1;
            break;
        default:
            break;
        }
        pushOperand(result);
    }
    printf("Infix evaluated result: %.2f\n\n", operand[topOperand]);
}
int precedence(char op){
    switch(op){
        case '+':
        case '-':
            return 1;
            break;
        case '/':
        case '*':
            return 2;
            break;
        default:
            break;
    }
    return -1;
}
void pushOperand(float number){
    if(topOperand==high-1)
        printf("Overflow!\n");
    else{
        topOperand++;
        operand[topOperand]=number;
    }
}
void pushOperator(char ch){
    float num1, num2, result;
	int precedenceOperand;
    char op1;
    if(topOperator==high-1)
        printf("Overflow!\n");
    else if(topOperator==-1){
        precedenceTop2=precedence(ch);
        topOperator++;
        operator[topOperator]=ch;
    }
    else{
        precedenceOperand=precedence(ch);
        if(precedenceOperand>precedenceTop2){
            topOperator++;
            operator[topOperator]=ch;
        }
        else{
            op1=popOperator();
            num1=popOperand();
            num2=popOperand();
            switch(op1){
            case '+':
                result=num2+num1;
                break;
            case '-':
                result=num2-num1;
                break;
            case '*':
                result=num2*num1;
                break;
            case '/':
                result=num2/num1;
                break;
            default:
                break;
            }
            pushOperand(result);
            topOperator++;
            operator[topOperator]=ch;
        }
    }
}
float popOperand(){
    float number;
    if(topOperand==-1)
        printf("Underflow!\n");
    else{
        number = operand[topOperand];
        topOperand--;
    }
    return number;
}
int popOperator(){
    char ch;
    if(topOperator==-1)
        printf("Underflow!\n");
    else{
        ch = operator[topOperator];
        topOperator--;
    }
    return ch;
} 

//Postfix function definitions
void postfix(){
    float num1, num2, result, digit;
    printf("Enter a postfix expression: ");
    scanf("%s", &post);
    printf("You entered: %s\n", post);
    for(e=post; *e!='\0'; e++){
        if(isdigit(*e)){
            digit = *e - '0';
            pushPostfix(digit);
        }
        else{
            num1 = popPostfix();
            num2 = popPostfix();
            switch(*e){
            case '+':
                result = num2 + num1;
                break;
            case '-':
                result = num2 - num1;
                break;
            case '*':
                result = num2 * num1;
                break;
            case '/':
                result = num2 / num1;
                break;
            }
            pushPostfix(result);
        }
    }
    printf("Postfix evaluated result: %.2f\n\n", postStack[topPost]);
}
void pushPostfix(float x){
    if(topPost==high-1)
        printf("Overflow!\n");
    else{
        topPost++;
        postStack[topPost]=x;
    }
}
float popPostfix(){
    float del;
    if(topPost==-1)
        printf("Underflow!\n");
    else{
        del = postStack[topPost];
        topPost--;
    }
    return del;
}

//Prefix function definitions
void prefix(){
    char ch, temp[high], str[high], pre[high];
    float num1, num2;
    int j;
    printf("Enter a prefix expression: ");
    scanf("%s", &str);
    printf("You entered %s\n", str);
    strcpy(pre, strrev(str));
    for(int i=0; str[i]!='\0'; i++){
        ch = str[i];
        if((ch >= '0' && ch <= '9')){
            j=0;
            temp[j]=str[i];
            j++;
            temp[j]='\0';
            pushPrefix(atoi(temp));
        }
        else{
            num2=popPrefix();
            num1=popPrefix();
            switch(str[i]){
            case '+':
                val=num2+num1;
                break;
            case '-':
                val=num2-num1;
                break;
            case '*':
                val=num2*num1;
                break;
            case '/':
                val=num2/num1;
                break;
            }
            pushPrefix(val);
        }
    }
    val=popPrefix();
    printf("Prefix evaluated value: %.2f\n\n", val);
}
void pushPrefix(float ch){
    if (topPre == high-1)
        printf("Overflow!\n");
    else{
        topPre++;
        preStack[topPre]=ch;
    }
}
float popPrefix(){
    float ch;
    if (topPre==-1)
        printf("Underflow!\n");
    else{
        ch = preStack[topPre];
        topPre--;
    }
    return ch;
}