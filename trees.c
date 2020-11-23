#include<stdio.h>
#include<stdlib.h>
struct  node
{
    int data;
    int count;
    struct node* left;
    struct node* right;
};

//creating global variable
struct node* root ;


//fuction to creat nodes of the trees
struct node* createNode(int data){
    struct node* temp ;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Null Pointer is assigned to the new node creatd\n");
        return NULL;
    }
    else
    {
        temp->count = 0 ;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    
}

int insert(int data){
    struct node* temp = root;
    if(root == NULL){
        root = createNode(data);
        return 0;
    }

    while((temp!=NULL)){
        if( (temp->data) > data){
           // printf("%d this is from insert-11\n",temp->data);
            if(temp->left == NULL){
                temp->left = createNode(data);
                printf("Insterted\n");
                return 0;
            }
            temp = temp->left;
        }
        else if(temp ->data == data)
        {
            printf("duplicate\n");
            return 0;
        }
        
        else {
            //printf("%d this is from insert\n",temp->data);
            if(temp->right == NULL){
                temp->right = createNode(data);
                printf("Inserted\n");
                return 0;
            }
            temp = temp->right;
        }
        
    } 
    return 0;
}

    


void printNode(struct node* temp){
    if(temp == NULL){
        return;
    }
    printNode(temp->left);
     printf("%d\t",temp->data);  
    printNode(temp->right);
    
   
    return ;

}

int main(){
    int number;
    while(1){
        printf("Enter the number to insert into the tree\n");
        scanf("%d",&number);
        if(number == -999){
            break;
        }
        else
        {
            insert(number);
        }
    }
    printNode(root);
    return 0;
}