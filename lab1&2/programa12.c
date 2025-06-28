#include <stdio.h>

void main() {
    int start, end, i, j, isPrime;

    printf("Enter the lower limit: ");
    scanf("%d", &start);
    printf("Enter the upper limit: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);

    for (i = start ; i<= end; i++) {
        if (i < 2) {
            continue; 
        }
        isPrime = 1; 
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", i);
        }
    }

}
