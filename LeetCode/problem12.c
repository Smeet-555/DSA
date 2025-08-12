#include <stdio.h>

void intToRoman(int num, char *result) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };

    result[0] = '\0'; 

    for (int i = 0; i < 13 && num > 0; i++) {
        while (num >= values[i]) {
            num -= values[i];
            strcat(result, symbols[i]);
        }
    }
}

int main() {
    int num;
    char roman[20]; 

    printf("Enter an integer (1–3999): ");
    scanf("%d", &num);

    if (num < 1 || num > 3999) {
        printf("Number out of range.\n");
        return 1;
    }

    intToRoman(num, roman);
    printf("Roman numeral: %s\n", roman);

    return 0;
}
