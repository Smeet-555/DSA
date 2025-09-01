#include <stdio.h>

#define m 10

int hashset[m];

void init() {
    for (int i = 0; i < m; i++) {
        hashset[i] = -1;
    }
}

int f(int key) {
    return key % m;
}

void add(int key) {
    int index = f(key);

    // Try linear probing up to m slots
    for (int probe = 0; probe < m; probe++) {
        int i = (index + probe) % m;

        if (hashset[i] == -1) {   // empty slot
            hashset[i] = key;
            return;
        } else if (hashset[i] == key) {   // already exists
            printf("Key %d already exists\n", key);
            return;
        }
    }

    // If loop ends, hashset is full
    printf("Hashset is full, cannot insert %d\n", key);
}

void display() {
    printf("Hashset: ");
    for (int i = 0; i < m; i++) {
        if (hashset[i] != -1)
            printf("%d ", hashset[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

int main() {
    init();

    add(10);
    add(20);
    add(30);
    add(40);
    add(50);
    add(20);  // duplicate test

    display();

    return 0;
}
