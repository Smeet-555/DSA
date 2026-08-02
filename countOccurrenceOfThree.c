#include <stdio.h>

int occurrenceOfThree(int arr[], int n) {


    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
    }


    int i = 0;

    while (i < n) {
        int count = 1;

        while (i + 1 < n && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }

        if (count < 3) {
            return 0;
        }

        i++;
    }

    return 1;
}

int main() {
    int arr[] = {1,1,1,3,3,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", occurrenceOfThree(arr, n));

    return 0;
}