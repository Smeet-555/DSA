#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node *link;
};

// Head pointer
struct node *first = NULL;

// Function declarations
void insertAtFirst();
void insertAtLast();
void sortList();
void display();

int main() {
    int key;

    do {
        printf("\n\n--- MENU ---");
        printf("\n0. Exit");
        printf("\n1. Insert at First");
        printf("\n2. Insert at Last");
        printf("\n3. Sort List");
        printf("\n4. Display List");
        printf("\nEnter your choice: ");
        scanf("%d", &key);

        switch (key) {
            case 0:
                printf("Exiting program.\n");
                break;
            case 1:
                insertAtFirst();
                break;
            case 2:
                insertAtLast();
                break;
            case 3:
                sortList();
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    } while (key != 0);

    return 0;
}

// Insert at the beginning
void insertAtFirst() {
    int x;
    printf("Enter value to insert at first: ");
    scanf("%d", &x);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->info = x;
    newNode->link = first;
    first = newNode;
}

// Insert at the end
void insertAtLast() {
    int x;
    printf("Enter value to insert at last: ");
    scanf("%d", &x);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
    } else {
        struct node *temp = first;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

// Sort the list (Bubble sort by value)
void sortList() {
    if (first == NULL || first->link == NULL) {
        printf("List is too short to sort.\n");
        return;
    }

    struct node *i, *j;
    for (i = first; i->link != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->info > j->info) {
                int temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }

    printf("List sorted in ascending order.\n");
}

// Display the list
void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = first;
    int index = 1;
    printf("\n--- Linked List Contents ---\n");
    while (temp != NULL) {
        printf("Node %d: %d\n", index++, temp->info);
        temp = temp->link;
    }
}
