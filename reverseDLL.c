#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

int main() {
    struct node *newnode, *temp, *head = NULL, *tail = NULL ,*current;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 50;
    newnode->next = NULL;
    newnode->prev = NULL;
    head = tail = newnode;


    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 5;
    newnode->next = NULL;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;


    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 51;
    newnode->next = NULL;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;

    printf("Before reversing\n");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    current = head;
    while (current!=NULL)
    {
        newnode = current ->next;
        current->next = current->prev;
        current -> prev = newnode;
        current = newnode;
    }

    current = head;
    head = tail;
    tail = current;

printf("After reversing:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;

}