#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};

struct node *head = NULL;

struct node *createNode()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter data : ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

void display()
{
    struct node *save = head;
    printf("\nNULL -> ");
    while (save != NULL)
    {
        printf("[lptr : %p| data : %d |rptr : %p] -> ", (struct node *)save->lptr, save->data, (struct node *)save->rptr);
        save = save->rptr;
    }
    printf("->NULL");
}

void insertFromLast(int count)
{
    for (int i = 0; i < count; i++)
    {
        struct node *newNode = createNode();
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct node *save = head;
            while (save->rptr != NULL)
            {
                save = save->rptr;
            }
            newNode->lptr = save;
            save->rptr = newNode;
        }
    }
}

void deleteAlternate()
{
    if (head == NULL || head->rptr == NULL)
    {
        printf("\nList has insufficient nodes to delete alternates.\n");
        return;
    }

    struct node *current = head;
    struct node *next;

    while (current != NULL && current->rptr != NULL)
    {
        next = current->rptr;

        current->rptr = next->rptr;

        if (next->rptr != NULL)
        {
            next->rptr->lptr = current;
        }

        free(next);

        current = current->rptr;
    }

    display();
}

int main()
{
    int key, count;
    while (1)
    {
        printf("\nEnter 1 to insert\nEnter 2 to delete alternate nodes\nEnter key : ");
        scanf("%d", &key);
        if (key == 1)
        {
            printf("Enter number of node to insert : ");
            scanf("%d", &count);
            insertFromLast(count);
            display();
        }
        else if (key == 2)
        {
            deleteAlternate();
        }
        else
        {
            printf("Invalid Key Input");
            break;
        }
    }
}