#include<stdio.h>
#include<string.h>
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
int pop(){
    if(!isEmpty()){
        //printf("Deleting : %c\n",stack[top]);
        top = top -1;
        return 0;
    }
    return -1;
}
int bracketBalanceChek(char* arr){
    int i = 0;
    int count = 0;
    int d;
    if(arr[0] == ')'){
            return -1;
        }
    while(arr[i] !='\0'){
       
        
        if(arr[i] =='('){
            count = 1;
            push(arr[i]);
        }
        else if(arr[i] == ')'){
            d = pop();
            if(d == -1){
                return -1;
            }
        }
        i++;
    }
    if (top != -1 ){
        return -1;
    }
    //to check if the string had any brackets
    else if (count == 0){
        return -2;
    }
    else if(top == -1 && count == 1){
        return 0;
    }
}
int main(){
    char arr[100];
    int d,i=0;
    printf("\nEnter the pattern: ");
    scanf("%s",arr);
    d = bracketBalanceChek(arr);
    //printf("\n%d\n",top);
    if(d == 0){
        printf("The brackets are balanced\n");
    }
    else if(d == -2){
        printf("No brackets at all\n");
        return 0;
    }
    else
    {
        printf("The brackets are not balanced \n");
    }
    return 0;
}