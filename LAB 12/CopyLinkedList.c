#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;

void insertAtLast(int count)
{
    for (int i = 0; i < count; i++)
    {
        int x;
        printf("Enter info : ");
        scanf("%d", &x);
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = x;
        newNode->link = NULL;
        struct node *save = first;

        if (first == NULL)
        {
            first = newNode;
        }
        else
        {
            while (save->link != NULL)
            {
                save = save->link;
            }
            save->link = newNode;
        }
    }
}

void sortList()
{
    if (first == NULL || first->link == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *i, *j;
    for (i = first; i->link != NULL; i = i->link)
    {
        for (j = i->link; j != NULL; j = j->link)
        {
            if (i->info > j->info)
            {
                int temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

void display()
{
    struct node *save = first;

    if (first == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        do
        {
            printf("[info : %d | link : %p] -> ", save->info, (void *)save->link);
            save = save->link;

        } while (save != NULL);
    }
    printf("NULL");
}

void removeDuplicate()
{
    sortList();
    struct node *current = first;
    struct node *next = current->link;
    while (next != NULL)
    {
        if (current->info == next->info)
        {
            current->link = next->link;
            next->link = NULL;
            next = current->link;
        }
        else
        {
            current = current->link;
            next = current->link;            
        }
    }
    display();
}

int main()
{

    int x, key, count;
    while (1)
    {
        printf("\nEnter 1 to Insert\nEnter 2 to Remove Duplicates\nEnter key : ");
        scanf("%d", &key);
        if (key == 1)
        {
            printf("Enter number of nodes : ");
            scanf("%d", &count);
            insertAtLast(count);
            display();
        }
        else if (key == 2)
        {
            removeDuplicate();
        }
        else
        {
            printf("Invalid key input.\n");
        }
    }
}