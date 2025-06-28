#include <stdio.h>

int main() {
    int base, exponent;
    int result = 1;

    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exponent);

    for (int i = 1; i <= exponent; i++) {
        result *= base;
    }

    printf("%d to the power %d is %d\n", base, exponent, result);

    return 0;
}
