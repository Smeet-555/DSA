#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 10;
    newnode->next = head;
    head = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 20;
    newnode->next = head;
    head = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 30;
    newnode->next = head;
    head = newnode;

    if (head == NULL) {
        printf("List is empty.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);  
        temp->next = NULL; 
    }

    printf("List after deleting last node:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
