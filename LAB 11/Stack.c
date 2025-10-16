// Stack Bucket Like structure LIFO
// Functions
// Push : Insert from first
// push  : delete from first
// Top  : return first

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* head = NULL;

int isEmpty() {
    return head == NULL;
}

int getData() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    return data;
}
int getNodeCount() {
    int count;
    printf("Enter number of nodes to push: ");
    scanf("%d", &count);
    return count;
}

void push() {
    int count = getNodeCount();
    for (int i = 0; i < count; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            return;
        }

        newNode->data = getData();
        newNode->next = NULL;

        if (isEmpty()) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
}

int top() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return head->data;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    struct node* temp = head;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. pop\n3. Top\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3: {
                int front = top();
                if (front != -1)
                    printf("Front: %d\n", front);
                break;
            }
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
