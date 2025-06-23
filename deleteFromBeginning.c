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
    newnode->data = 10;
    newnode->next = head;  
    head = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 20;
    newnode->next = head;  
    head = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = 30;
    newnode->next = head;  
    head = newnode;


    struct node *temp ;
    temp = head;
    head = head->next;
    free (temp);

    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); 
    
}