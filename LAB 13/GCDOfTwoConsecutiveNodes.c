#include <stdio.h>
#include <stdlib.h>
void insertAtLast(int count);
void display();
int GCD(int x,int y);
void ConNodes();

struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;

int main()
{

    int x, key, count;
    while (1)
    {
        printf("\nEnter key : ");
        scanf("%d", &key);
        if (key == 1)
        {
            printf("Enter number of nodes : ");
            scanf("%d", &count);
            if (count%2==0)
            {
                insertAtLast(count);
                display();
            }
            else
            {
                printf("Invalid number of nodes {nodes should be even}");
            }
        }
        else if (key == 2)
        {
            ConNodes();
        }
        else
        {
            break;
        }
    }
}

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

void ConNodes(){
    struct node *current,*next;
    current = first;
    next = first->link;
    while (current && next)
    {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->info = GCD(current->info,next->info);
        newNode->link = NULL;

        newNode->link = current->link;
        current->link = newNode;
        if (next->link)
        {
            current = next->link;
            next = current->link;
        }
        else
        {
            break;
        }
    }

    display();
    
}

int GCD(int x,int y)
{
    int i = (x<y)?x:y; 
    for (i; i != 0; i--)
    {
        if (x%i == 0 && y%i ==0)
        {
            return i;
            break;
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