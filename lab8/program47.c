#include <stdio.h>
#include <stdlib.h>

int r = 0, f = 0;

void enque(int val, int size, int queue[]) {
    if ((r + 1) % size == f) {
        printf("Queue overflow\n");
        return;
    }
    queue[r] = val;
    r = (r + 1) % size;
}

void dequeue(int size, int queue[]) {
    if (f == r) {
        printf("Queue underflow\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[f]);
    f = (f + 1) % size;
}

void display(int queue[], int size) {
    if (f == r) {
        printf("Queue is empty\n");
        return;
    }

    int i = f;
    printf("Queue elements: ");
    while (i != r) {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int size, choice, val;
    printf("Enter the size of queue: ");
    scanf("%d", &size);

    int queue[size];

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enque(val, size, queue);
                break;

            case 2:
                dequeue(size, queue);
                break;

            case 3:
                display(queue, size);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

