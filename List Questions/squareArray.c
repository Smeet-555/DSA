#include <stdio.h>

int main() {
    int n;
    printf("Enter the size: ");
    scanf("%d" , &n);
    int size = 2 * n - 1; 
    int arr[size][size];        
    int i, j, start = 0, end = size - 1;
    int k = n;

    while (k > 0) {
        for (i = start; i <= end; i++) {
            for (j = start; j <= end; j++) {
                if (i == start || i == end || j == start || j == end) {
                    arr[i][j] = k;
                }
            }
        }
        start++;
        end--;
        k--;
    }

    // Print the pattern
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}