#include<stdio.h>
#include<limits.h>

int main(){
    int size , i , j ,index,max, k;
    printf("Enter the size of the array: ");
    scanf("%d" , &size);
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element " , (i+1));
        scanf("%d" , &arr[i]);
    }
    

    printf("Enter the value of k: ");
    scanf("%d" , &k);

    for (int i = 0; i < k; i++) {
        max = INT_MIN;
        index = -1;

        for (int j = 0; j < size; j++) {
            if (arr[j] > max) {
                max = arr[j];
                index = j;
            }
        }

        arr[index] = INT_MIN;
    }

    printf("the value of kTH largest element is %d" , k);
    

}