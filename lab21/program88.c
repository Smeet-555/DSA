// Binary search

#include <stdio.h>

// iterative approach
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  

        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            low = mid + 1;  
        }
        else {
            high = mid - 1; 
        }
    }
    return -1;  
}
int main() {
    // int numbers[] = {1, 3, 5, 7, 9, 11, 13};
    // int size = sizeof(numbers) / sizeof(numbers[0]);
    // int target = 7;

    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter elements of array : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }

    int target;
    printf("Enter target : ");
    scanf("%d",&target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
