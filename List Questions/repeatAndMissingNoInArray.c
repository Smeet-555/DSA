#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    int count[size + 1]; 
    for (int i = 0; i <= size; i++) {
        count[i] = 0; 
    }


    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        count[arr[i]]++;
    }

    int duplicate = -1, missing = -1;
    for (int i = 1; i <= size; i++) {
        if (count[i] == 0) {
            missing = i;
        } else if (count[i] == 2) {
            duplicate = i;
        }
    }

    printf("\nDuplicate number: %d\n", duplicate);
    printf("Missing number: %d\n", missing);

    return 0;
}
