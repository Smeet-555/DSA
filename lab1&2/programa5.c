#include<stdio.h>

int factorial();
int main(){
    printf("Enter any number to find the factorial:");
    int n;
    scanf("%d" , &n);
    int i = 1;
    printf("%d" ,factorial(n));
}
int factorial(int n){
    if(n==1 || n==0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }

}