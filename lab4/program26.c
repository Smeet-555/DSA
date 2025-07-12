#include <stdio.h>

int main() {
    int size1 , size2;
    
    printf("Enter the size of array 1: ");
    scanf("%d", &size1);
    
    int arr[size1];

    printf("Enter the size of array 1: ");
    scanf("%d", &size2);
    
    int arr[size2];
    
    printf("Enter the elements in array 1:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the elements in array 2:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr[i]);
    }

    int arr[size1+size2];
    for (int i = 0; i < size1+size2; i++)
    {
        
    }
    
}