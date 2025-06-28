#include<stdio.h>

int main(){
    int count = 0;
    int num;
    printf("Enter a number: ");
    scanf("%d" , &num);
    for(int i  = 2; i<num ; i++){
        if(num%i==0){
            count++;
            break;
        }
    }

    if(count==0){
        printf("Prime number");
    }
    else{
        printf("Not a Prime");
    }

}