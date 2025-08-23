#include <stdio.h>
#include <stdlib.h>

int f = -1, r = -1; 

void insertAtLast(int val, int size, int queue[]) {
    if ((r + 1) % size == f) {
        printf("Queue overflow\n");
        return;
    }
    if (f == -1) {  
        f = r = 0;
    } else {
        r = (r + 1) % size;
    }
    queue[r] = val;
}

void insertAtFirst(int val, int size, int queue[]) {
    if ((r + 1) % size == f) {
        printf("Queue overflow\n");
        return;
    }
    if (f == -1) { 
        f = r = 0;
    } else {
        f = (f - 1 + size) % size;
    }
    queue[f] = val;
}

void dequeueAtFirst(int size, int queue[]) {
    if (f == -1) {
        printf("Queue underflow\n");
        return;
    }
    printf("Deleted from front: %d\n", queue[f]);
    if (f == r) { 
        f = r = -1;
    } else {
        f = (f + 1) % size;
    }
}

void dequeueAtLast(int size, int queue[]) {
    if (f == -1) {
        printf("Queue underflow\n");
        return;
    }
    printf("Deleted from rear: %d\n", queue[r]);
    if (f == r) { 
        f = r = -1;
    } else {
        r = (r - 1 + size) % size;
    }
}

void display(int queue[], int size) {
    if (f == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = f;
    while (1) {
        printf("%d ", queue[i]);
        if (i == r) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int size, choice, val;
    printf("Enter the size of deque: ");
    scanf("%d", &size);

    int queue[size];

    while (1) {
        printf("\n--- Menu (Double Ended Queue) ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtFirst(val, size, queue);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtLast(val, size, queue);
                break;

            case 3:
                dequeueAtFirst(size, queue);
                break;

            case 4:
                dequeueAtLast(size, queue);
                break;

            case 5:
                display(queue, size);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
