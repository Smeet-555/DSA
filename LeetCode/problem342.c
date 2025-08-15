#include <stdio.h>
#include <stdbool.h>


bool isPowerOfFour(int n) {
    if (n <= 0) return false; 
    while (n > 1) {
        if (n % 4 != 0) {
            return false; 
        }
        n /= 4;
    }

    return true; 
}

int main() {
    int testCases[] = {1, 4, 16, 64, 5, 8, 256, 1024, 218, -4, 0};
    int size = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < size; i++) {
        int num = testCases[i];
        if (isPowerOfFour(num)) {
            printf("%d is a power of four.\n", num);
        } else {
            printf("%d is NOT a power of four.\n", num);
        }
    }

    return 0;
}
