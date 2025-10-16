// Queue FIFO first in first out   Front <> Rear
// Operations 
// Enqueue/Push : Add from rear
// Dequeue/Pop : Delete from front
// Front/Peek : Shows front data


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
    printf("Enter number of nodes to enqueue: ");
    scanf("%d", &count);
    return count;
}

void enqueue() {
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
            struct node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return head->data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = head;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3: {
                int front = peek();
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
