// LINEAR SEARCH

#include <stdio.h>  
#include <time.h>  

int linearSearch(int array[],int size,int n){
    for (int i = 0; i < size; i++)
    {
        if (n == array[i])
        {
            return i;
        }
    }
    return -1;
}

int main(){

    int size,n;
    double esTime;

    printf("Enter size of array : ");
    scanf("%d",&size);
    int array[size];   
    
    printf("Enter elements of array.\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&array[i]);
    };
    
    printf("Enter number to search : ");
    scanf("%d",&n);

    double start=clock();
    int x = linearSearch(array,size,n);
    
    double end = clock();


    esTime = ((end - start) / CLOCKS_PER_SEC)*1000;
    printf("index : %d , time taken : %f",x,esTime);
        
    return 0;
}

