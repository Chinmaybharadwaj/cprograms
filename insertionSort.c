// c program to implement insertion sort

#include<stdio.h>
#include<stdlib.h>
int insertionSort(int* arr,int size){
    int i,key,j;
    int *temp = (int*)malloc(size * sizeof(int));
    if(temp == NULL){
        printf("Null Pointer\n");
        return -1;
    }
    for(i = 1;i<size;i++){
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return 1;

    
}
int main(){
    int *arr;
    int num,i;
    printf("Enter the number to element you want to insert");
    scanf("%d",&num);

    arr = (int*)malloc(num*sizeof(int));
    
    for(i=0;i<num;i++){
        printf("\nEnter the element:");
        //!!!
        scanf("%d",arr+i);
    }
    printf("Element inside the array after insetion\n");
    insertionSort(arr,num);
    for(i=0;i<num;i++){
        printf("%d\n",arr[i]);
        //printf("%d\n",*(arr+i));
    }
    return 0;
}