#include<stdio.h>

int main(){
    int size,index = 1;
    printf("Enter the size of array");
    scanf("%d" , &size);
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter the element at %d: " , (i+1));
        scanf("%d" , &arr[i]);
    }

    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[index++] = arr[i];
        }
    }

    printf("Array after removing consecutive duplicates:\n");
    for (int i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    

}