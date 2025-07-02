#include<stdio.h>


// iterative approach
// int maxSubArraySum(int arr[] , int size){
//     int maxSum = arr[0];

//     for (int i = 0; i < size ;i++){
//         int currSum = 0;
//         for (int j = i; j < size; j++)
//         {
//             currSum += arr[j];
//         }
//         if (currSum > maxSum)
//         {
//             maxSum = currSum;
//         }
//     }
//     return maxSum;
// }



// kadane's algo
int kadanesAlgo(int arr[] , int size){
    int result =arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < size; i++)
    {
        maxEnding = (maxEnding + arr[i] > arr[i]) ? maxEnding +arr[i] : arr[i];
        result = (result > maxEnding )? result : maxEnding;
    }
    return result;
  
}
int main(){
    int size;
    printf("Enter the size of array: ");
    scanf("%d" , &size);
    int arr[size];
    printf("Enter the elements of array\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter the element ");
        scanf("%d" , &arr[i]);
    }

    // printf("%d " , maxSubArraySum(arr , size));
    printf("%d " , kadanesAlgo(arr , size));
}