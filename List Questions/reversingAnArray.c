#include<stdio.h>

void reverseArray(int arr[] , int size){
    for (int i = 0; i < size/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    };
}
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
        printf("%d " , arr[i]);
    }

    reverseArray(arr, size);
    printf("\nThe reversed array  is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d " , arr[i]);
    }
    
}