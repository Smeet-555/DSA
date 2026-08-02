#include <stdio.h>
#include <string.h>

void runLengthEncode(char str[]) {
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        int count = 1;

        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        printf("%c%d", str[i], count);
    }

    printf("\n");
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    scanf("%s", str);

    runLengthEncode(str);

    return 0;
}