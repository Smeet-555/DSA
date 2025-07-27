#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = NULL;
    int size;
    int capacity = 2;

    array = malloc(capacity * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &array[i]);
    }

    int carry = 1;
    for (int i = size - 1; i >= 0; i--) {
        int sum = array[i] + carry;
        array[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry == 1) {
        array = realloc(array, (size + 1) * sizeof(int));
        for (int i = size; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = 1;
        size++;
    }
    


    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    free(array);  
    return 0;
}
