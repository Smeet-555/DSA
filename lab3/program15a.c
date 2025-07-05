#include<stdio.h>

int main(){
    int n;
    float avg ,sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d" , &n);
    for ( int i = 1; i <= n; i++)
    {
        sum+=i;
    }
    avg = sum/n;
    printf("%.2f" , avg);
}