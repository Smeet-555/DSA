#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

int main() {
    struct node *newnode, *temp, *head = NULL, *tail = NULL;

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
    newnode->data = 510;
    newnode->next = NULL;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;

    printf("Before deletion:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");


    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);  
    }

    printf("After deletion:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
