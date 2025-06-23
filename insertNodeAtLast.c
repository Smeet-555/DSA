#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main(){
    struct node* head = NULL;

    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    newnode -> data = 10;
    newnode -> next = head;
    head = newnode;
    
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode -> data = 20;
    newnode -> next = head;
    head = newnode;

    newnode = (struct node *) malloc(sizeof(struct node));
    newnode -> data = 30;
    newnode -> next = 0; 

    struct node *temp = head;
    while (temp -> next != 0)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
