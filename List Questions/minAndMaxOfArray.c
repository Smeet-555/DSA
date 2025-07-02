#include<stdio.h>
int main(){
    int size;
    printf("Enter the size of array: ");
    scanf("%d" , &size);
    int arr[size];
    printf("Enter the elements of array\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter the element ");
        scanf("%d" , &arr[i]);
    }

    printf("The array entered is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d \n" , arr[i]);
    }

    int max = arr[0];
    int min = arr[0]; 

    for (int i = 0; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    printf("The max element is: %d\n" , max);
    printf("The min element is: %d" , min);

    
    
}