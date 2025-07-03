#include<stdio.h>

// search in sorted rotated array
// naive approach
// int main(){
//     int size , match = 0;
//     printf("Enter the size of the array: ");
//     scanf("%d" , &size);
//     int arr[size];
//     printf("\nEnter the elements of the array: ");
//     for (int i = 0; i < size; i++)
//     {
//             printf("\nEnter the element %d position: ",(i+1));
//             scanf("%d" , &arr[i]);
//     }
//     int target;
//     printf("Enter the target value: ");
//     scanf("%d" , &target);
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == target)
//         {
//                 printf("%d" , i);
//                 match = 1;
//                 break;
//         }
//         else
//         {
//             match = 0;
//         }
//     }
//     if (match == 0)
//     {
//         printf("%d" , -1);
//     }
// }

int searchIndex(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {
            if (arr[mid] < target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}


    
int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the sorted rotated array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    int index = searchIndex(arr, size, target);

    if (index != -1)
        printf("Target %d found at index %d.\n", target, index);
    else
        printf("Target %d not found in the array.\n", target);

    return 0;

}