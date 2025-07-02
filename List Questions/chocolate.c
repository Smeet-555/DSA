#include<stdio.h>

int main(){
    int n = 12;
    int chocolate = n;
    int wrapper = n;
    
    for (int i = 0; i < n; i++)
    {
        int rem = (wrapper/3);
            chocolate+= rem;
        wrapper = rem + (wrapper%3);
        
    }
    printf("%d" , chocolate);
}