#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *newnodeA, *tempA, *headA = NULL;
    int node1, i = 0;

    printf("Enter the number of nodes in first LL: ");
    scanf("%d", &node1);

    while (i < node1)
    {
        newnodeA = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data to insert: ");
        scanf("%d", &newnodeA->data);
        newnodeA->next = headA;
        headA = newnodeA;
        i++;
    }

    printf("First Linked list: ");
    tempA = headA;
    while (tempA != NULL)
    {
        printf("%d ->", tempA->data);
        tempA = tempA->next;
    }
    printf("NULL\n");

    struct node *newnodeB, *tempB, *headB = NULL;
    int node2, j = 0;

    printf("Enter the number of nodes in second LL: ");
    scanf("%d", &node2);

    while (j < node2)
    {
        newnodeB = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data to insert: ");
        scanf("%d", &newnodeB->data);
        newnodeB->next = headB;
        headB = newnodeB;
        j++;
    }

    printf("Second Linked list: ");
    tempB = headB;
    while (tempB != NULL)
    {
        printf("%d ->", tempB->data);
        tempB = tempB->next;
    }
    printf("NULL\n");

    struct node *ptrA = headA;
    struct node *ptrB = headB;
    int flag = 1;

    while (ptrA != NULL && ptrB != NULL)
    {
        if (ptrA->data != ptrB->data)
        {
            flag = 0;
            break;
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    if (ptrA != NULL || ptrB != NULL)
    {
        flag = 0;
    }

    if (flag == 1)
    {
        printf("Linked lists are SAME.\n");
    }
    else
    {
        printf("Linked lists are NOT SAME.\n");
    }

    return 0;
}
