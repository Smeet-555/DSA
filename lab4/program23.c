#include <stdio.h>

int main() {
    int size, num, i, j;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[100];

    printf("Enter %d elements in ascending order:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    for (i = 0; i < size; i++) {
        if (arr[i] > num) {
            break;
        }
    }

    for (j = size; j > i; j--) {
        arr[j] = arr[j - 1];
    }

    arr[i] = num;
    size++;

    printf("Array after insertion:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
