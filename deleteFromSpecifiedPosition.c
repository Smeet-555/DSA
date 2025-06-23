#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *nextnode;
    int pos, i = 1;

    struct node *newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 2;
    newnode->next = head;
    head = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 1;
    newnode->next = head;
    head = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 6;
    newnode->next = head;
    head = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 5;
    newnode->next = head;
    head = newnode;

    printf("Original List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
    } else {
        temp = head;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
            nextnode = temp->next;
            temp->next = nextnode->next;
            free(nextnode);
        
    }

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
