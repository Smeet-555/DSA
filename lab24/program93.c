#include <stdio.h>

#define MAX 100

int a[MAX]; 

void merge(int low, int mid, int high) {
    int h, i, j, k;
    int b[MAX]; 

    h = low;
    i = low;
    j = mid + 1;

    while (h <= mid && j <= high) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h = h + 1;
        } 
        else {
            b[i] = a[j];
            j = j + 1;
        }
        i = i + 1;
    }

    if (h > mid) {
        for (k = j; k <= high; k++) {
            b[i] = a[k];
            i = i + 1;
        }
    } 
    else {
        for (k = h; k <= mid; k++) {
            b[i] = a[k];
            i = i + 1;
        }
    }

    for (k = low; k <= high; k++) {
        a[k] = b[k];
    }
}


void mergeSort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergeSort(0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
