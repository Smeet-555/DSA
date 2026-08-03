#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void dominantNumbers(int arr[], int n) {
    sort(arr, n);

    int uniqueCount = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            uniqueCount++;
        }
    }

    printf("Number of unique elements = %d\n", uniqueCount);

    int found = 0;
    int i = 0;

    while (i < n) {
        int count = 1;

        while (i + 1 < n && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }

        if (count > uniqueCount) {
            printf("%d ", arr[i]);
            found = 1;
        }

        i++;
    }

    if (!found) {
        printf("No Dominant Number Found");
    }

    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 1, 1, 4, 5, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    dominantNumbers(arr, n);

    return 0;
}