#include <stdio.h>

int countDigit(int digit, int start, int end){
    int count = 0;

    for(int i = start; i <= end; i++){
        int number = i;

        while(number > 0){
            if(number % 10 == digit){
                count++;
            }

            number = number / 10;
        }
    }

    return count;
}

int main(){
    int digit, start, end;

    printf("Enter a digit (0-9): ");
    scanf("%d", &digit);

    printf("Enter the start of the range: ");
    scanf("%d", &start);

    printf("Enter the end of the range: ");
    scanf("%d", &end);

    if(digit < 0 || digit > 9){
        printf("Please enter a valid digit between 0 and 9.\n");
        return 1;
    }

    int occurrence = countDigit(digit, start, end);

    printf("The digit %d occurs %d times in the range [%d, %d].\n",
           digit, occurrence, start, end);

    return 0;
}