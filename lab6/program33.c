#include<stdio.h>

int swap(int a  , int b){
    int temp = a;
    a = b;
    b = temp;
    printf("%d " , a);
    printf("%d" , b);
    return 0 ;
}
int main(){
    int a , b;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d" , &b);

    printf("After swapping the value of a and b: ");
    swap(a,b);

}