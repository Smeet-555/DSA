#include <stdio.h>

int main() {
    int size1, size2;

    printf("Enter the size of array1: ");
    scanf("%d", &size1);
    int arr1[size1];

    printf("Plz enter sorted elements for array1:\n");
    for (int i = 0; i < size1; i++) {
        printf("Enter the element at %d: ", i);
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of array2: ");
    scanf("%d", &size2);
    int arr2[size2];

    printf("Plz enter sorted elements for array2:\n");
    for (int i = 0; i < size2; i++) {
        printf("Enter the element at %d: ", i);
        scanf("%d", &arr2[i]);
    }

    int n = size1 + size2;
    int result[n];

    // Merge arrays
    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    printf("Merged and sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    if (n % 2 == 0) {
        int mid1 = n / 2 - 1;
        int mid2 = n / 2;
        float median = (result[mid1] + result[mid2]) / 2.0;
        printf("Median: %.2f\n", median);
    } else {
        int mid = n / 2;
        printf("Median: %d\n", result[mid]);
    }

    return 0;
}
