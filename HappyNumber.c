#include <stdio.h>

int sumOfSquares(int num) {
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }

    return sum;
}

int isHappy(int num) {

    while (num != 1 && num != 4) {
        num = sumOfSquares(num);
    }

    if (num == 1)
        return 1;
    else
        return 0;
}

int main() {

    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isHappy(num))
        printf("%d is a Happy Number.\n", num);
    else
        printf("%d is Not a Happy Number.\n", num);

    return 0;
}