#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* Lptr;
    struct Node* Rptr;
};

struct Node* head = NULL;

void insertFront(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->Lptr = NULL;
    newNode->Rptr = head;

    if (head != NULL)
        head->Lptr = newNode;

    head = newNode;

    printf("%d inserted at the front.\n", data);
}

void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->Rptr = NULL;

    if (head == NULL) {
        newNode->Lptr = NULL;
        head = newNode;
        printf("%d inserted at the end.\n", data);
        return;
    }

    struct Node* temp = head;
    while (temp->Rptr != NULL)
        temp = temp->Rptr;

    temp->Rptr = newNode;
    newNode->Lptr = temp;

    printf("%d inserted at the end.\n", data);
}

void deleteAtPosition(int pos) {
    if (head == NULL || pos <= 0) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    struct Node* temp = head;
    int i;

    for (i = 1; temp != NULL && i < pos; i++)
        temp = temp->Rptr;

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp->Lptr != NULL)
        temp->Lptr->Rptr = temp->Rptr;
    else
        head = temp->Rptr;

    if (temp->Rptr != NULL)
        temp->Rptr->Lptr = temp->Lptr;

    printf("Deleted node at position %d with value %d.\n", pos, temp->data);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->Rptr;
    }
    printf("\n");
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete at position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
