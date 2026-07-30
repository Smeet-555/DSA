#include <stdio.h>
#include <string.h>

void nextBigNumber(char num[]) {
    int n = strlen(num);
    int i, j;


    i = n - 2;

    while(i >= 0 && num[i] >= num[i + 1]) {
        i--;
    }

    if(i < 0) {
        printf("No next bigger number exists.\n");
        return;
    }


    j = n - 1;

    while(num[j] <= num[i]) {
        j--;
    }

    char temp = num[i];
    num[i] = num[j];
    num[j] = temp;


    int left = i + 1;
    int right = n - 1;

    while(left < right) {
        temp = num[left];
        num[left] = num[right];
        num[right] = temp;

        left++;
        right--;
    }

    printf("Next bigger number: %s\n", num);
}

int main() {
    char num[100];

    printf("Enter a number: ");
    scanf("%s", num);

    nextBigNumber(num);

    return 0;
}