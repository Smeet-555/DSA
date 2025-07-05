#include<stdio.h>

int main(){
    int  size , num;
    printf("Enter the size of array");
    scanf("%d" , &size);
    int arr[size];
    printf("Enter the elements :\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d" , &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i; i < size; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("Array contains duplicate numbers");
                break;
            }
            else{
                printf("Does not contains duplicates");
                break;
            }
            
        }
        break;
        
        
    }
}