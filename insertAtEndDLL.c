#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
    
};

int main(){
    struct node *newnode , *temp ,*head = NULL, *tail;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode ->data = 10;
    newnode ->prev = 0;
    newnode ->next = 0;
    head = temp = newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode ->data = 5;
    newnode ->prev = temp;
    newnode ->next = 0;
    temp -> next = newnode;
    tail = newnode;

    temp = head;
    while (temp!=NULL)
    {
        printf("%d <->" , temp ->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
    


}


