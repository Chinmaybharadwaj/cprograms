#include<stdio.h>
#include<error.h>

//to display the arry element where arr is the pointer to the arry and n is the number of element in array
void display(int *arr,int *n){
    int i = 0,s;
    s = *n;
    for(i = 0;i < s;i++){
        printf("%d\n",*(arr+i));
    }
}

// function to insert dummy values
void insertDummy(int *arry ,int *capacity){
    int i = 0;
    int start = *(capacity);
    for(i = start;i<(start+10);i++){
        arry[i] = i; 
    }
    *capacity = *capacity + i;
}
//this function inserts the element in the index
int insertion(int *arr,int *capacity,int element,int index){
    int i,temp,temp2;
    int size = *(capacity);
   

    if ( (size + 1 > 100) || index < 0 || index >=100){
        return -1;
    }    
    temp = arr[index];
    temp2 = arr[index];
    // the below is to slide is from the index point
    // for(i = index + 1; i < 100 ; i++){
    //         temp = arr[i];
    //         arr[i] = temp2;
    //         temp2 = temp;

    // } 
    
    for(i = *capacity ; i >= index ;i--){
        arr[i+1] = arr[i];
        
    }
    
    arr[index] = element;
    return 0;
}

int deletion(int *arr,int *capacity,int index){
    int i = index;
    if(index < 0 || index >=(*(capacity))){
        return -1;
    }
    for(i = index;i<*(capacity);i++){
        arr[i] = arr[i+1];
    }
    *(capacity)--; 
    return 0;
}


int main(){
    int arr[100];
    int *capacity = 0;
    int status = 0;
    insertDummy(arr,&capacity);
    
     insertion(arr,&capacity,2222,1);
        //insertion(arr,&capacity,2222,6);
        display(arr,&capacity);
        status = deletion(arr,&capacity,2);
        if(status == -1){
            perror("dummy error");
        }
        printf("After deletion\n");
        display(arr,&capacity);


    return 0;
}