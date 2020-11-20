/*c program to convert inifix expression to postfix expression valid operators are +,-,*,/,(,) 
without use of precedence function
*/
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
int precedence(char a){
    switch(a){
        case '+' :  return 1;
                    break;
        case '-' :  return 1;
                    break;
        case '*' :  return 2;
                    break;
        case '/' :  return 2;
                    break;
        default :
                    break;
    }
}
char* infixToPostfix(char *infix){
    char postfix[100];
    char ch;
    int i = 0;
    int j = 0;
    if(infix[0] == ')'){
        printf("Invalid infix expression\n");
        return NULL;
    }
    while(infix[i]!='\0'){
        if(isalpha(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(infix[i] == '('){
                push(infix[i]);
                i++;
            }
            else if(infix[i] == '*' ||infix[i] == '/'){
                if(stack[top] == '+' || stack[top] == '-'||stack[top] == '('){
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
                if(stack[top] == '('){
                    push(infix[i]);
                    i++;
                }
                else{
                    while(!isEmpty()){
                        postfix[j] = pop();
                        j++;
                    }
                    push(infix[i]);
                    i++;
                }

            }
            else if (infix[i] == ')'){
                while(top != -1){
                    ch = pop();
                    if(ch != '('){
                        postfix[j] = ch;
                        j++;
                    }
                }
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