#include <stdio.h>

int main() {
    int size, min, max ,flag=1;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i]>arr[i+1])
        {
            flag =0;
        }
        
    }

    if (flag == 0)
    {
        printf("%d" , 0);
    }
    else{

    min = arr[0];
    max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Min is %d\n", min);
    printf("Max is %d\n", max);

    return 0;
    }
    
    

}
