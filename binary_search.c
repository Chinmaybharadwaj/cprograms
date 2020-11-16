#include<stdio.h>
#include<stdlib.h>


//to swap two numbers
void swap(int* num1,int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


//function for selection sort
void sort(int* arry,int size){
    int i,j;
    int min_index;
    int index = 0;
    for(i = 0;i<size;i++){
        min_index  = i;
        for(j = i+1 ;j<size;j++){
            if(arry[min_index] >= arry[j]){
                min_index = j;
            }
        }
        swap(&arry[i],&arry[min_index]);

        
    }
}

//function to display the array element
void display(int *arry,int size){
    int i;
    for(i = 0;i<size;i++){
        printf("%d\n",arry[i]);
    }
}

//funcitont to implement the binary search

int binary_searcy(int *arry,int l,int r,int key){
    int mid;
    while(r>=l){
        printf("1\n");
        mid = l +((r-l)/2);
        if(arry[mid]== key){
            printf("Element found: %d\n",arry[mid]);
            return mid;
        }
        else if (arry[mid]>key){
            binary_searcy(arry,mid+1,l,key);

        }
        else {
            r = mid-1;
            binary_searcy(arry,r,mid-1,key);
        }
        return  -1;
    }
}

int main(){
    int array[30]= {3,-22,535,4,67,34,23,-1,233} ;
    int size = 9;
    int key;
    sort(array,size);
    display(array,size);
    printf("Enter the number you want to search : ");
    scanf("%d",&key);
    binary_searcy(array,0,size-1,key);
    return 0;
}
