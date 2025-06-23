#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL; 
    int count = 0; 

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
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("the number of nodes is: %d" , count);

    return 0;
}