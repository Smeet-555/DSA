#include<stdio.h>

int main(){
    printf("Enter any alphabet:");
    char ch;
    scanf("%c" , &ch);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'  ){
        printf("Vowel");
    }
    else{
        printf("Consonant");
    }
}