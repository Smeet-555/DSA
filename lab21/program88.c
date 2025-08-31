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

// recursive approach
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; 
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid; 
    }
    else if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, high, target);  
    }
    else {
        return binarySearchRecursive(arr, low, mid - 1, target);  
    }
}

int main() {
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter elements of array (sorted): \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }

    int target;
    printf("Enter target : ");
    scanf("%d",&target);

    // Iterative approach
    int iterartiveResult = binarySearch(arr, size, target);

    if ( iterartiveResult!= -1) {
        printf("[Iterative] Element found at index %d\n", iterartiveResult);
    } else {
        printf("[Iterative] Element not found\n");
    }

    // Recursive approach
    int iterartiveResult = binarySearchRecursive(arr, 0, size - 1, target);

    if (iterartiveResult != -1) {
        printf("[Recursive] Element found at index %d\n", iterartiveResult);
    } else {
        printf("[Recursive] Element not found\n");
    }

    return 0;
}
