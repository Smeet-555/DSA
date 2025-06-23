#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node *prevnode = NULL, *currentnode, *nextnode;

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 10;
    new_node->next = head;
    head = new_node;

    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 20;
    new_node->next = head;
    head = new_node;

    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 30;
    new_node->next = head;
    head = new_node;


    struct Node* temp = head;

    printf("Before reversing \n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    currentnode = head;
    while (currentnode !=NULL)
    {
        nextnode = currentnode ->next;
        currentnode ->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    
    head = prevnode;
    temp = head;
    printf("After reversing\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    


    return 0;
}
