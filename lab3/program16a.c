#include<stdio.h>

int main(){
    int  size , min , max;
    printf("Enter the size of array");
    scanf("%d" , &size);
    int arr[size];
    printf("Enter the elements :\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d" , &arr[i]);
    }
    min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else
        {
            max = arr[i];
        }
        
    }

    printf("the minimum number is: %d\n" , min);
    printf("The maximum number is: %d" , max);
}