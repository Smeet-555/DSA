#include<stdio.h>

int main() {
    int size, position, newNum;
    
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size + 1];
    
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the index at which you want to insert the element: ");
    scanf("%d", &position);


    printf("Enter the new element to insert: ");
    scanf("%d", &newNum);

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = newNum;
    size++;

    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
