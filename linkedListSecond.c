#include<stdio.h>
#include<stdlib.h>
//incomplete code idea is to write c program to create multiple linked list and store them in sepearte list 
//2d linked list
struct node {
    int data;
    struct node *next;
};
struct node* createNewNode(){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        perror(temp);
        return NULL;
    }
    return temp;
}

struct node* createNewList(){
    static struct node* head;
    static int count;
    struct node* temp = NULL;
    if(head == NULL){
        head = createNewNode();
        head->data = count++;
        printf("New List has been succesfully created\n");
        return head;
    }
    else{
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("New List has been successfully created\n");
        temp->next = createNewNode();
        (temp->next)->data = count++;
        return head;
    } 
}

int traversList(){

}

int main(){
    int choice;
    int num;
    int errStat = 0;
    while(1){
        printf("Enter the choice:\n 1:insert\t 2:delet\t 3.search\t 4.revers\t 5.display\t 6.exit\n");
        scanf("%d",&choice); 
        switch(choice){
            case 1 :        
                        break;
            case 2 :    printf("\nEnter the element to delet : ");
                        scanf("%d",&num);
                        errStat = deletNode(num);
                        break;
            case 3 :
                        break;
            case 4 :
                        break;
            case 5 :    printList();
                        break;
            case 6 :    printf("------------------------exiting--------------------\n");
                        exit(0);                        
                        break;
            default:
                        break;            
        }
    }
    return 0;
}