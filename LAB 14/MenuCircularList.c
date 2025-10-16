#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *loopLast = NULL;

void insertFront(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (loopLast == NULL)
    {
        loopLast = newNode;
        loopLast->next = loopLast;
    }
    else
    {
        newNode->next = loopLast->next;
        loopLast->next = newNode;
    }

    printf("%d inserted at the front.\n", data);
}

void insertEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (loopLast == NULL)
    {
        loopLast = newNode;
        loopLast->next = loopLast;
    }
    else
    {
        newNode->next = loopLast->next;
        loopLast->next = newNode;
        loopLast = newNode;
    }

    printf("%d inserted at the end.\n", data);
}

void deleteAtPosition(int pos)
{
    if (loopLast == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = loopLast->next, *prev = loopLast;
    int count = 1;

    if (pos == 1)
    {
        if (loopLast == loopLast->next)
        {
            free(loopLast);
            loopLast = NULL;
        }
        else
        {
            loopLast->next = temp->next;
            free(temp);
        }
        printf("Node at position %d deleted.\n", pos);
    }
    else
    {
        while (count < pos && temp != loopLast)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (count == pos)
        {
            prev->next = temp->next;
            if (temp == loopLast)
                loopLast = prev;
            free(temp);
            printf("Node at position %d deleted.\n", pos);
        }
        else
        {
            printf("Position out of range.\n");
        }
    }
}

void display()
{
    if (loopLast == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = loopLast->next;
    printf("Circular Linked List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != loopLast->next);
    printf("\n");
}

int main()
{
    int choice, val, pos;

    while (1)
    {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete at position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &val);
            insertFront(val);
            break;
        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
