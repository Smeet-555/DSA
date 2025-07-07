#include<stdio.h>

int main(){
    int  size , num ,newNum , temp;
    printf("Enter the size of array");
    scanf("%d" , &size);
    int arr[size];
    printf("Enter the elements :\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d" , &arr[i]);
    }
    printf("Enter the number from the array you want to replace:");
    scanf("%d" , &num);
    printf("Enter the number to replace:");
    scanf("%d" , &newNum);

    printf("Array before replacing");
    for (int i = 0; i < size; i++)
    {   
        printf(" %d " , arr[i]);
    }
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            arr[i] = newNum;
            int temp = i;
            printf("\nElement replaced at index %d \n" , temp);        
        }
    }
    printf("Array after replacing");
        for (int i = 0; i < size; i++)
    {   
        printf(" %d " , arr[i]);
    }
    
}