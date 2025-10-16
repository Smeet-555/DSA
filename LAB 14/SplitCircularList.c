#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *insert(struct node *first)
{
    int x;
    printf("\nEnter the value to be inserted: ");
    scanf("%d", &x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if (first == NULL)
    {
        newnode->link = newnode;
        first = newnode;
    }
    else
    {
        struct node *save = first;
        while (save->link != first)
        {
            save = save->link;
        }
        save->link = newnode;
        newnode->link = first;
    }
    return first;
}
struct node *split(struct node *first){
    if (first == NULL || first->link == first) {
        printf("List too small to split.\n");
        return NULL;
    }
    struct node *slow = first;
    struct node *fast = first;
    while (fast->link!=first && fast->link->link!=first){
        slow=slow->link;
        fast=fast->link->link;
    }
    if (fast->link->link==first)
    {
        fast=fast->link;
    }
    struct node  *fh=first;
    struct node  *sh=slow->link;
    slow->link=first;
    fast->link=sh;
    struct node *save1=fh;
    struct node *save2=sh;
    printf("first half is:\n");
    do
    {
        printf("%d ", save1->info);
        save1=save1->link;
    } while (save1!=fh);
    printf("\nsecond half is:\n");
    do
    {
        printf("%d ", save2->info);
        save2=save2->link;
    } while (save2!=sh);
}
void display(struct node *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *save = first;
    do
    {
        printf("%d ", save->info);
        save = save->link;
    } while (save != first);
}
void main()
{
    struct node *first = NULL;
    int choice;
    while (1)
    {
        printf("\n1. Insert node in the list");
        printf("\n2. Print the list");
        printf("\n3. Exit");
        printf("\n4. Split and display two halves of the list");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insert(first);
            break;
        case 2:
            display(first);
            break;
        case 3:
            exit(0);
            break;
        case 4:
        {
            split(first);
            break;
        }
        default:
            break;
        }
    }
}