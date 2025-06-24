#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main() {
    struct node *head = NULL, *tail = NULL;
    struct node *newnode, *temp;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 10;
    newnode->prev = NULL;
    newnode->next = NULL;
    head = tail = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 5;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }

    head = newnode;

    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    temp = tail;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");

    return 0;
}
