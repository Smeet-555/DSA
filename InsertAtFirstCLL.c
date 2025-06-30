#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int choice = 1;
    struct node *head = NULL, *newNode, *temp, *tail = NULL;

    while (choice) {
        newNode = (struct node*) malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);

        if (head == NULL) {
            head = tail = newNode;
            newNode->next = head;  
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }

        printf("Enter 1 to continue and 0 to exit: ");
        scanf("%d", &choice);
    }


    newNode = (struct node*) malloc(sizeof(struct node));
    printf("Enter data to insert at beginning: ");
    scanf("%d", &newNode->data);

    newNode->next = head;    
    tail->next = newNode;    
    head = newNode;          

    printf("Circular Linked List:\n");
    temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(connect back to head)\n");

    return 0;
}
