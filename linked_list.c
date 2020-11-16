//implemetation of linked list with global head variable
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct  node *next;
};

// global variable to store the starting point of the linked list.
struct  node *head = NULL;

void printList(){
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    
    printf("[");
    while(temp != NULL)
    {
        printf("%d" ,temp->data);
        temp = temp->next;
        if(temp != NULL){
            printf(",");
        }
    }   
    printf("]\n");
     
}

int insertData(int data){
    //temporary variable
    struct node * temp ;
    struct node *new = (struct node*)malloc(sizeof(struct node));    
    new->data = data;
    
    if(head == NULL){
        head = new;
        return 0;
    }
    else{
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        return 0;
    }
    return -1;
}

int deletNode(int key){
    struct node* temp = head;
    struct node* prev =NULL;
    struct node* next = NULL;
   
    
    if(temp == NULL){
        printf("No Elements in the list/underflow\n");
        return -1;
    }
    else if(temp->data == key){
        printf("Element found : %d [will be deleted]\n",temp->data);
        temp = head;
        head = head->next;
        free(temp);
        return 0;
    }
    while(temp != NULL){
        prev = temp;
        next = temp->next;
        
        if(temp->data == key){
            printf("Element found : %d\n [will be deleted]\n",temp->data);
            prev = temp ->next;
           free(temp); 
        }
        
        return 0;
    }
    return -1;
}

int main(){
    int choice;
    int num;
    int errStat = 0;
    while(1){
        printf("Enter the choice:\n 1:insert\t 2:delet\t 3.search\t 4.revers\t 5.display\t 6.exit\n");
        scanf("%d",&choice); 
        switch(choice){
            case 1 :    printf("\nEnter the element to insert : ");
                        scanf("%d",&num);
                        errStat = insertData(num);    
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