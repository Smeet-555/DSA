#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node *newnode, *headA = NULL, *headB = NULL, *tempA, *tempB;

    // Creating linked list A: 34 -> 11 -> 12
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 12;
    newnode->next = NULL;
    headA = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 11;
    newnode->next = headA;
    headA = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 34;
    newnode->next = headA;
    headA = newnode;

    // Copying list A to B
    tempA = headA;
    while (tempA != NULL) {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = tempA->data;
        newnode->next = NULL;

        if (headB == NULL) {
            headB = tempB = newnode;
        } else {
            tempB->next = newnode;
            tempB = newnode;
        }

        tempA = tempA->next;
    }

    printf("Before copying LL (List A):\n");
    tempA = headA;
    while (tempA != NULL) {
        printf("%d -> ", tempA->data);
        tempA = tempA->next;
    }
    printf("NULL\n");

    printf("After copying LL (List B):\n");
    tempB = headB;
    while (tempB != NULL) {
        printf("%d -> ", tempB->data);
        tempB = tempB->next;
    }
    printf("NULL\n");

    return 0;
}
