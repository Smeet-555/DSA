#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int size, result = 0, mul =1;
    
    printf("Enter size for array : ");
    scanf("%d",&size);
    
    int *ptr = (int*)malloc(sizeof(int));
    
    printf("\nEnter array elements :\n");
    for(int i = 0 ; i < size ; i++){
        scanf("%d",ptr+i);
    }
    printf("\nArray elements are :\n");
    for(int i = 0 ; i < size ; i++){
        printf("%d\n",*(ptr+i));
        result = result + (*(ptr+i));
        mul = mul * (*(ptr+i));
    }

    printf("\nArray sum : %d\n",result);

    printf("\nArray multiplication : %d\n",mul);

    free(ptr);
    
    return 0;

}