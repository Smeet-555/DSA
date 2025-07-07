#include<stdio.h>
#include<math.h>

int main(){
    int rows , num;
    printf("Enter the number of rows to print: ");
    scanf("%d", &rows);
    for (int i = 0; i <=rows; i++)
    {
            int num = pow(11,i);
            printf("%d\n" , num);
    }


    
}
