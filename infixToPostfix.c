//c program to convert inifix expression to postfix expression valid operators are +,-,*,/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100];
int top =-1;
int MAXSIZE = 100;



int isEmpty(){
    if(top == -1){
        return 1;
    }
    else 
        return 0;
}
int isFull(){
    if(top == MAXSIZE){
        return -1;
    }
    else 
        return 0;
}
int peek(){
    if(top == -1){
        return -1;
    }
    else
        return stack[top];

}
int push(char data){
    if(!isFull()){
        top = top + 1;
        stack[top] = data;
       // printf("The number/character has been pushed\n");
        return 0;
    }
    printf("Cannot be inserted\n");
    return -1;
}
char pop(){
    if(!isEmpty()){
        //printf("Deleting : %c\n",stack[top]);
        //top = top -1;
        return stack[top--];
    }
    return -1;
}
char* infixToPostfix(char *infix){
    char postfix[100];
    int i = 0;
    int j = 0;
    while(infix[i]!='\0'){
        if(isalpha(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(infix[i] == '*' ||infix[i] == '/'){
                if(stack[top] == '+' || stack[top] == '-'){
                    push(infix[i]);
                    i++;
                }
                else
                {
                    postfix[j] = pop();
                    push(infix[i]);
                    j++;
                    i++;
                }
            }
            else if(infix[i] == '+' || infix[i] == '-')
            {
                while(!isEmpty()){
                    postfix[j] = pop();
                    j++;
                }
                push(infix[i]);
                i++;

            }
        }
    }
    postfix[j] = pop();
    j++;
    postfix[j] =pop();
    if(top != -1){
        printf("The infix expression is not valid\n");
    }
    printf("this is the postfix expression: %s",postfix);
    return postfix;
}
int main(){
    char arr[100];
    int d,i=0;
    printf("Enter the postfix expression:");
    scanf("%s",arr);
    infixToPostfix(arr);
    
    return 0;
}