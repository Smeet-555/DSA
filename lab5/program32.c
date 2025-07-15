#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int size;
    srand(time(NULL));
    int index = rand()%size;

    printf("Enter the size of character array: ");
    scanf("%d" , &size);
    char ch1[size][100];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the words: ");
        scanf("%c" , &ch1[i][100]);
    }
    char word[100];
    printf("Enter the word: ");
    scanf("%c" , &word[100]);




    
    
}