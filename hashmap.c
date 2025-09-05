#include <stdio.h>
#include <stdlib.h>

#define m 10

struct pair {
    char key;       // single character key
    int value;      // value associated
    int occupied;   // 0 = empty, 1 = occupied
};

struct pair hashmap[m];

int f(char key) {
    return key % m;
}

void add(char key, int value) {
    int index = f(key);

    for (int probe = 0; probe < m; probe++) {
        int i = (index + probe) % m;

        if (!hashmap[i].occupied) {   
            hashmap[i].key = key;
            hashmap[i].value = value;
            hashmap[i].occupied = 1;
            return;
        }
        else if (hashmap[i].occupied && hashmap[i].key == key) {
            printf("Key %c already exists, updating value.\n", key);
            hashmap[i].value = value;
            return;
        }
    }

    printf("Hashmap is full, cannot insert %c\n", key);
}

void display() {
    printf("Hashmap:\n");
    for (int i = 0; i < m; i++) {
        if (hashmap[i].occupied)
            printf("[%d] -> (%c , %d)\n", i, hashmap[i].key, hashmap[i].value);
        else
            printf("[%d] -> empty\n", i);
    }
}

int main() {
    for (int i = 0; i < m; i++) {
        hashmap[i].occupied = 0;
    }

    add('A', 10);
    add('B', 20);
    add('C', 30);
    add('A', 40); 

    display();

    return 0;
}
