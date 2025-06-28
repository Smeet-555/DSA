#include<stdio.h>

int main(){
    printf("Enter any number:");
    int a;
    scanf("%d" , &a);
    if(a%2==0){
        printf("Even");
    }
    else{
        printf("Odd");
    }
}