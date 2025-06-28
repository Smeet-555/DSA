#include<stdio.h>

int main(){
    printf("Enter any number to find the factorial:");
    int a;
    scanf("%d" , &a);
    int fact=1;
    for(int i = 1;i<=a;i++){
        fact = fact*i;
    }
    printf("%d" , fact);
}