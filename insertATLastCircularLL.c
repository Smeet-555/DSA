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
    newNode->data = 99;  
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
    tail->next->data = 3; 

    tail ->next->data = 3;
    temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");

    return 0;

    return 0;

}
