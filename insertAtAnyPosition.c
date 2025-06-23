#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main(){
    int position = 2;
    int i = 1;
    struct node *head = NULL;
    struct node *temp;

    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode -> data = 10;
    newnode ->next = head;
    head = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode -> data = 20;
    newnode ->next = head;
    head = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode -> data = 30;
    newnode ->next = head;
    head = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    
    temp = head;
        while (i < position - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }



    printf("Enter data : " );
    scanf("%d", &newnode->data);
    newnode -> next = temp -> next;
    temp -> next = newnode;

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");


}