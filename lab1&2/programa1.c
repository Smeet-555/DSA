#include<stdio.h>

int main(){
    printf("Enter radius:");
    double r;
    scanf("%lf" , &r);
    double area = 3.14*r*r;
    printf("%lf",area);

    return 0;
}