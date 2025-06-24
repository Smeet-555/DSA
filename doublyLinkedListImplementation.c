#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1;

    while (choice) {
        newnode = (struct node*) malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);


        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Do you want to continue (1 = Yes / 0 = No)? ");
        scanf("%d", &choice);
    }
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
