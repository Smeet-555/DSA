#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main(){
struct node *head, *newNode ,*temp;
head = 0;

newNode = (struct node *) malloc (sizeof (struct node));

printf("Enter data");
scanf("%d" , &newNode -> data);
newNode->next = 0;

if (head == 0)
{
    head = temp = newNode;    
}else
{
    temp ->next = newNode;
    temp = newNode;
}


}
