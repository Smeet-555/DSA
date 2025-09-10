#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int lb, int ub) {
    int key = arr[lb];   
    int i = lb, j = ub + 1;
    int flag = 1;

    while (flag) {
        do {
            i++;
        } while (i <= ub && arr[i] < key);


        do {
            j--;
        } while (arr[j] > key);

        if (i < j) {
            swap(arr, i, j);
        } else {
            flag = 0;
        }
    }
    swap(arr, lb, j); 
    return j;
}


void quick_sort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int j = partition(arr, lb, ub);
        quick_sort(arr, lb, j - 1);
        quick_sort(arr, j + 1, ub);
    }
}

int main() {
    int arr[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
