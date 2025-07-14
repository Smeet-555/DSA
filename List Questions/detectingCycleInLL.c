#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node* head = (struct node*) malloc(sizeof(struct node));
    struct node* second = (struct node*) malloc(sizeof(struct node));
    struct node* third = (struct node*) malloc(sizeof(struct node));
    struct node* fourth = (struct node*) malloc(sizeof(struct node));
    struct node *temp1 = head;
    struct node *temp2 = head;

    head->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create a cycle: point fourth's next back to second
    // fourth->next = second;

while (temp1 != NULL && temp1->next != NULL) {
        temp2 = temp2->next;           
        temp1 = temp1->next->next;     

        if (temp1 == temp2) {
            printf("Cycle detected");
            return 0;
            break;
        }
    }
    printf("No cycle detcted");

    return 0;
}
