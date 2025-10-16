#include <stdio.h>
#include <stdlib.h>
void insertAtLast(int count);
void swapNum();
void display();

struct node
{
    int info;
    struct node *link;
};
struct node *first=NULL;

int main(){
    
    int x, key, count;
    while (1)
    {
        printf("\nEnter key : ");
        scanf("%d",&key);
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
            swapNum();
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

void swapNum(){
    struct node *temp1,*temp2,*temp3;
    temp1 = first;
    temp2 = first->link;
    temp3 = NULL;
    first = temp2;
    
    while(1)
    {
       temp1->link = temp2->link;
       temp2->link = temp1;
       if (temp3)
       {
            temp3->link = temp2;
       }
       temp3 = temp1;
       temp1 = temp1->link;
       if (temp1)
       {
            temp2 = temp1->link;
       }
       else
       {
            break;
       }
       
    }
    
    display();
}

void display(){
    struct node *save = first;
    
    if(first == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        do
        {
            printf("[info : %d | link : %p] -> ", save->info, (void*)save->link);
            save = save->link;
            
        }
        while (save != NULL);
        
    }
    printf("NULL");
}