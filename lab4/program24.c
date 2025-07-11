#include <stdio.h>

int main() {
    int size, num, i, pos = -1;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[100];

    printf("Enter %d elements in ascending order:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to delete: ");
    scanf("%d", &num);


    for (i = 0; i < size; i++) {
        if (arr[i] == num) {
            pos = i;
            break;
        }
    }
        for (i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
            size--;


        printf("Array after deletion:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }


