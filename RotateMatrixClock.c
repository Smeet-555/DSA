#include <stdio.h>
int main()
{
    int m, n;

    printf("Enter the value of m & n: ");
    scanf("%d %d", &m, &n);

    int arr[m][n];

    int new_arr[n][m];

    printf("Enter the elements of array: ");
    for(int i=0; i<m; i++ ){
        for (int j = 0; j< n; j++)
        {
            printf("Enter the element at %d,%d: " , i,j);
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = n-1; i >=0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            new_arr[j][n-1-i] = arr[i][j];
        }
        
    }
    
    printf("The new array is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", new_arr[i][j]);
        }
        printf("\n");
    }

}   