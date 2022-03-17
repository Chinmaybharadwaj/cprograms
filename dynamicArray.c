#include<stdio.h>
#include<stdlib.h>


int* getArrayPointer();
void printDynamicArray(int* arrayPointer,int size);

int main(){
    int sizeofArray;
    int* arrayPointer;
    int iterator = 0;
    printf("Enter the size of the array\n");
    scanf("%d",&sizeofArray);
    arrayPointer = getArrayPointer(sizeofArray);
    
    printf("Enter the number\n");
    for(iterator=0;iterator<sizeofArray;iterator++){
        int element;
       
        scanf("%d",&element);
        arrayPointer[iterator]=element;
    }

    printDynamicArray(arrayPointer,sizeofArray);
    return 0;
}


int* getArrayPointer(int sizeOfArray){
     
    int* arrayPointer =(int*)malloc(sizeOfArray*sizeof(int));

    return arrayPointer;

}

void printDynamicArray(int* arrayPointer,int size){
    int* array = arrayPointer;
    int iterator;
    printf("Displaying the array\n");
    for(iterator = 0;iterator<size;iterator++){
        printf("%d\n",array[iterator]);
    }
}