#include<stdio.h>

int main() {
    int size, position;
    
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size + 1];
    
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the index at which you want to delete the element: ");
    scanf("%d", &position);


    for (int i = position; i < size; i++) {
        arr[i] = arr[i+1];
    }
    size--;

    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
