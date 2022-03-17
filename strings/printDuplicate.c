#include<stdio.h>
#include<string.h>


int* getDuplicateAphabet(char* string);

int main(){

    char string[124];
    int sizeOfString;
    int* duplicate;
    int iterator = 0;
    printf("Enter the string\n");

    scanf("%s",string);
    //int asccii = string[0];
    //printf("%d\n",asccii);
    duplicate = getDuplicateAphabet(string);
    for(iterator = 0;iterator<26;iterator++){
        if(duplicate[iterator]>0){
            printf("Count of %c in the sentence is = %d\n",97+iterator,duplicate[iterator]);
        }
    }
    
}


int* getDuplicateAphabet(char* string){

    int string2[26];
   
    int iterator;
    int index;

    for(iterator=0;iterator<26;iterator++){
        string2[iterator] = 0;
    }
    for(iterator=0;string[iterator] != '\0';iterator++){
        index=(string[iterator])-97;
        //printf("%d\n",string2[index]);
        string2[index]++;
    }

    return string2;
}