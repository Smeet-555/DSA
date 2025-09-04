#include<stdio.h>

// INSERTION SORT
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

    int i = 0,j=0 , key;
        while (i< size)
        {
           key = arr[i];
           j = i-1;
           while (j>=0 && arr[j] > key)
           {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                j--;
           }
           arr[j+1] = key;
           i++;
        }
    

    printf("Sorted array : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);   
    }
}