#include<stdio.h>

int main(){
    int n;
    printf("Enter the array Size : ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element at %d ",i);
        scanf("%d" , &arr[i]);
    }

    int num;
    printf("Enter any number: ");
    scanf("%d" , &num);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            printf("index of num is: %d" , i);
            break;
        }
        else if(arr[i]>num){
            printf("index of num is: %d" , i);
            break; 
        } 
        if (num > arr[n-1])
        {
            printf("index of num is: %d" , n);
            break;
        }
    }   
}