#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int size;
    
    printf("Enter size for array : ");
    scanf("%d",&size);
    
    int *ptr = (int*)malloc(sizeof(int));
    
    printf("\nEnter array elements :\n");
    for(int i = 0 ; i < size ; i++){
        scanf("%d",ptr+i);
    }

    printf("\nArray elements before sorting :\n");
    for(int i = 0 ; i < size ; i++){
        printf("%d ",*(ptr+i));
    }


    for(int i = 0 ; i < size ; i++){
        for(int j = i+1 ; j < size ; j++){
            if(*(ptr+i) < *(ptr+j))
            {
                int temp = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }

    printf("\nArray elements after sorting :\n");
    for(int i = 0 ; i < size ; i++){
        printf("%d ",*(ptr+i)); 
    }

    printf("\n\nMaximum  : %d",*(ptr));
    printf("\nMinimum  : %d\n",*(ptr+size-1));

    free(ptr);
    
    return 0;

}