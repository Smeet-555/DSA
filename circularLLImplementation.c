#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main(){
    int choice = 1;
    struct node *head=NULL, *newNode ,*temp ;

    
    while (choice)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d" , &newNode -> data);
        newNode->next = 0;

        if (head==0)
        {
            head = temp = newNode;
        }

        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        temp->next = head;

        printf("Enter 1 to continue and 0 to exit: ");
        scanf("%d" , &choice);
    }
    temp = head;
    do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);

    return 0;

}
