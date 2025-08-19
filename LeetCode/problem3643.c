#include<stdio.h>

int main(){
    int n , m;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    printf("\nEnter the number of columns : ");
    scanf("%d3",&m);
    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
        printf("Enter the element");
        scanf("%d",&arr[i][j]);
        }
    }
    
    
    int x , y;
    printf("\nEnter the starting row of matrix: ");
    scanf("%d",&x);
    printf("\nEnter the starting column of matrix: ");
    scanf("%d",&y);

    int k;
    printf("\nEnter the size of square matrix you want to select: ");
    scanf("%d",&k);

    printf("\nBefore reversing the rows\n");

    for (int i = x; i < x+k; i++)
    {
        for (int j = y; j < y+k; j++)
        {
            printf("%d ",arr[i][j]);
        }  
    }

    printf("\nAfter reversing the rows\n");
        // Reverse rows of submatrix
    printf("\nThe submatrix after reversing rows is:\n");
    for (int i = x + k - 1; i >= x; i--) { // start from last row of submatrix
        for (int j = y; j < y + k; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}
