#include <stdio.h>

#define N 3
int top = -1;
int s[N];

void push(int value) {
    if (top >= N - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        s[top] = value;
        printf("Pushed: %d\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int val = s[top];
        top--;
        return val;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int peep(int i) {
    if (top - i + 1 < 0) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return s[top - i + 1];
    }
}

void change(int i, int value) {
    if (top - i + 1 < 0) {
        printf("Invalid position\n");
    } else {
        s[top - i + 1] = value;
        printf("Changed element %d from top to %d\n", i, value);
    }
}

void main() {
    int choice;
    while (1) {
        printf("\n\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peep\n");
        printf("5. Change\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int value, i;
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Enter i-th element from top to peep: ");
                scanf("%d", &i);
                value = peep(i);
                if (value != -1)
                    printf("Peeped value: %d\n", value);
                break;

            case 5:
                printf("Enter i-th element from top to change: ");
                scanf("%d", &i);
                printf("Enter new value: ");
                scanf("%d", &value);
                change(i, value);
                break;

            case 6:
                printf("Exiting...\n");
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}
