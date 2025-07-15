#include<stdio.h>
int main(){
    int rows,column,element;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of column: ");
    scanf("%d", &column);
    int arr1[rows][column];
    printf("Enter the elements of first matrix\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter the element: ");
            scanf("%d" , &arr1[i][j]);
        }
    }
    int arr2[rows][column];
    printf("Enter the elements of second matrix\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter the element: ");
            scanf("%d" , &arr2[i][j]);
        }
    }
    int result[rows][column];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < column; j++)
            {
                result[i][j] = arr1[i][j]+ arr2[i][j];
            }
        }
        printf("after the sum of matrix:\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("%d  " , result[i][j]);
            }
            printf("\n");
        }
    
    
}