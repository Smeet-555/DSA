#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

int main() {
    struct node *newnode, *temp, *head = NULL, *tail = NULL;
    int position , i=0;
    printf("Enter the position of the node to delete: ");
    scanf("%d" , &position);

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


    // before deletion
    printf("Original List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    if (head == NULL) {
        printf("List is empty.\n");
    } else if (position == 1) {
        temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    } else {
        temp = head;
        i = 1;
    printf("NULL\n");



    while (i < position && temp != NULL) {
        temp = temp->next;
        i++;
    }

            if (temp == NULL) {
            printf("Invalid position.\n");
        } else {
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            if (temp == tail)
                tail = temp->prev;
            free(temp);
        }
    }

    // after deletion
    printf("List after deletion:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");


}
