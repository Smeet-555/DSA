#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* headA = NULL, *headB = NULL;  

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 30;
    new_node->next = headA;  
    headA = new_node;

    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 20;
    new_node->next = headA;  
    headA = new_node;

    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 10;
    new_node->next = headA;  
    headA = new_node;


    struct Node* tempA = headA;
    printf("First Linked List: ");
    while (tempA != NULL) {
        printf("%d -> ", tempA->data);
        tempA = tempA->next;
    }
    printf("NULL\n");

    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 5;
    new_node->next = headB;  
    headB = new_node;

    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 10;
    new_node->next = headB;  
    headB = new_node;

    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 15;
    new_node->next = headB;  
    headB = new_node;


    struct Node* tempB = headB;
    printf("Second Linked List: ");
    while (tempB != NULL) {
        printf("%d -> ", tempB->data);
        tempB = tempB->next;
    }
    printf("NULL\n");

    struct Node* tail = headA;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = headB;


    struct Node* pointA= headA;
    while (pointA != NULL) {
        struct Node* pointB = pointA->next;
        while (pointB != NULL) {
            if (pointA->data > pointB->data) {
                int temp = pointA->data;
                pointA->data = pointB->data;
                pointB->data = temp;
            }
            pointB = pointB->next;
        }
       pointA= pointA->next;
    }

    
    printf("merged Linked List: ");
    struct Node* tempC = headA;
    while (tempC != NULL) {
        printf("%d -> ", tempC->data);
        tempC = tempC->next;
    }
    printf("NULL\n");

    

}
