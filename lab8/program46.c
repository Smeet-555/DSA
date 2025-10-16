#include <stdio.h>
#include <stdlib.h>

int r = 0, f = 0;  

void enqueue(int val, int size, int queue[]) {
    if (r >= size) {
        printf("Queue Overflow!\n");
        return;
    }
    queue[r++] = val;
    printf("%d inserted into queue.\n", val);
}

void dequeue(int size, int queue[]) {
    if (r == f) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d deleted from queue.\n", queue[f]);
    f++;
}

void display(int queue[], int size) {
    if (r == f) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = f; i < r; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int size, choice, val;
    printf("Enter the size of queue: ");
    scanf("%d", &size);
    int queue[size];

    do {
        printf("\n==== MENU ====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val, size, queue);
                break;
            case 2:
                dequeue(size, queue);
                break;
            case 3:
                display(queue, size);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}
