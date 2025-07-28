#include<stdio.h>

int main(){
    int n , val;
    printf("Enter n:");
    scanf("%d" , &n);

    for (int i = 1; i*i <=n; i++)
    {
            if ((n/i) <= i*i)
            {
                val = i;
            }
        
    }

    printf("%d" , val);
    
}