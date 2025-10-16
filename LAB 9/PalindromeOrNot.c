#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int size,flag=1 ;
    
    printf("Enter size for array : ");
    scanf("%d",&size);
    
    char *ptr = (char*)malloc(sizeof(char));
    
    printf("\nEnter array elements :\n");
    for(int i = 0 ; i < size ; i++){
        scanf("%d",ptr+i);
    }

    for(int i = 0 ; i < size ; i++){
        if(*(ptr+i) == *(ptr+size-i-1))
        {
            printf("Not Palindrome");
            flag = 0;
            break;
        }
    }

    if(flag == 1){
    printf("\nIs Palindrome");

    }

    free(ptr);
    
    return 0;

}