#include<stdio.h>

int main(){
    int m , n , sum = 0;
    printf("Enter the starting value(m): ");
    scanf("%d" , &m);
    printf("Enter the ending value(n): ");
    scanf("%d" , &n);

    for (int i = m; i <= n; i++)
    {
        sum+=i;
    }
    printf("%d" , sum);
    
}