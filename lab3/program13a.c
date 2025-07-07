#include<stdio.h>

int main(){
    int  size;
    printf("Enter the size of array");
    scanf("%d" , &size);
    int arr[size];
    printf("Enter the elements :\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d" , &arr[i]);
    }

    printf("The elements of array are:");
    for (int i = 0; i < size; i++)
    {
        printf("%d " , arr[i]);
    }
}