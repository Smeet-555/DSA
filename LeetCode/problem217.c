// brute force approach


// #include<stdio.h>

// int main(){
//     int size , flag =0;
//     printf("Enter the size of array ");
//     scanf("%d" , &size);
//     int arr[size];

//     for (int i = 0; i < size; i++)
//     {
//         printf("Enter the element at %d index: ", i);
//         scanf("%d" , &arr[i]);
//     }
    

//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i+1; j < size; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 flag = 1;
//                 break;
//             }
//         }
        
//     }

//     if (flag == 1)
//     {
//         printf("True");
//     }
//     else{
//         printf("False");
//     }
    
    
// }