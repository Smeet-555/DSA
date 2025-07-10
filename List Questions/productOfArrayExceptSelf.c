#include<stdio.h>

int main(){
    int i = 0 , index = 0 , product = 1 , flag =1 , size;
    int arr[size];
    printf("Enter the size of array: ");
    scanf("%d" , &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element at %d: ",(i+1));
        scanf("%d" , &arr[i]);
    }
    
    int result[size];

    while (flag)
    {
        if (i < size)
        {
            if (i != index)
            {
                product = product * arr[i];
                i++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i = 0;
            result[index]= product;
            product = 1;
            index++;
        }
        if (index >= size)
        {
            flag = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d " , result[i]);
    }
    
    
}