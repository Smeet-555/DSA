#include<stdio.h>

// SELECTION SORT
int main(){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];

    printf("Enter elements of array : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);

    }

    for (int i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Sorted array : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);   
    }
}