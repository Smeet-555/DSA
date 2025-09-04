#include<stdio.h>

// BUBBLE SORT
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

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);   
    }
}