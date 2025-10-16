#include <stdio.h>
#include <stdlib.h>

int getData();
int countNodes();
void insertAtFirst();
void insertAtLast();
void deleteData();
void insertIntoOrderedList();
void display();
void sortList();
void reverseList();

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;
int x = 0;

int main(){

   int key;

    do {
        printf("\n-----------------------------------------\n");
        printf("Total nodes in LinkedList: %d\n", countNodes());
        printf("0 - Exit\n");
        printf("1 - Insert at first\n");
        printf("2 - Insert at last\n");
        printf("3 - Delete data\n");
        printf("4 - insert into ordered list data\n");
        printf("5 - Display list\n");
        printf("6 - Sort list\n");
        printf("7 - Reverse list\n");
        printf("Enter key: ");
        scanf("%d", &key);
        printf("\n");

        switch (key) {
            case 0: break;
            case 1: insertAtFirst(); break;
            case 2: insertAtLast(); break;
            case 3: deleteData(); break;
            case 4: insertIntoOrderedList(); break;
            case 5: display(); break;
            case 6: sortList(); break;
            case 7: reverseList(); break;
            default: printf("!! Invalid key try again\n"); break;
        }
    } while (key != 0);
    
    return 0;
}

int getData(){
    
    printf("Enter info : ");
    scanf("%d",&x);

    return(x);
}

int countNodes(){

    int count;
    struct node *save;

    count = 0;
    save = first;

    while (save != NULL)
    {
        save = save->link;
        count++;
    }
    
    return(count);
}

void insertAtFirst(){

    int num,i;

    printf("Inserting from First-Enter number of nodes : ");
    scanf("%d",&num);

    for (i = 0; i < num; i++)
    {
    
    x = getData();
    
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->info = x;
    newNode->link = first;

    first = newNode;

    }

}

void insertAtLast(){

    int num,i;

    printf("Inserting from Last-Enter number of nodes : ");
    scanf("%d",&num);

    for (i = 0; i < num; i++)
    {

        x = getData();

        struct node *newNode = (struct node*)malloc(sizeof(struct node));

        newNode->info = x;
        newNode->link = NULL;

        struct node *save = first;
        
        if(first == NULL)
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

void insertIntoOrderedList(){
    
    int num,i;

    printf("Inserting Nodes-Enter number of nodes : ");
    scanf("%d",&num);

    for (i = 0; i < num; i++)
    {
        
        x = getData();
        struct node *newNode = (struct node*)malloc(sizeof(struct node));

        newNode->info = x;
        newNode->link = NULL;
        
        if (first == NULL || x < first->info)
        {
            newNode->link = first;
            
            first = newNode;
        }
        else
        {
            struct node *save = first;
            struct node *pred;

            while (save != NULL && save->info <= x)
            {
                pred = save;
                save = save->link;
            }
            newNode->link = pred->link;
            pred->link = newNode; 
        }
        
    }
}

void deleteData(){
    
    if (first == NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {

        int num,i;

        printf("Deleting Nodes\nEnter number of nodes : ");
        scanf("%d",&num);

        for (i = 0; i < num; i++)
        {

            x = getData();

            struct node *save = first;
            struct node *pred;

            while (save->link != NULL && save->info != x)
            {
                pred = save;
                save = save->link;
            }

            if (first->info == x)
            {
                save = first;
                first = first->link;
                free(save);
            }
            

            else if(save->info == x)
            {
                pred->link = save->link;
                save->link = NULL;
                free(save);
            }
            
            else if(first->info != x)
            {
                printf("Data <%d> not found\n",x);
            }
    }
    
}
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
            printf("[info : %d | link : %d] -> ",save->info,save->link);
            save = save->link;
            
        }
        while (save != NULL);
        
    }
    printf("NULL");
}

void sortList(){

    if(first == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        printf("Sorted\n");
        struct node *save = first;
        struct node *pred = save;
        
        for (save ; save!=NULL ; save = save->link)
        {
            for (pred = save->link ; pred!=NULL ; pred = pred->link)
            {
                if (save->info > pred->info)
                {
                    int temp = save->info;
                    save->info = pred->info;
                    pred->info = temp;
                }
            }
        }
        display();
    }    
}

void reverseList(){

    if(first == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct node *pred = NULL;
        struct node *current = first;
        struct node *next = NULL;
        
        while (current != NULL)
        {
            next = current->link;
            current->link = pred;
            pred = current;
            current = next;
        }
        
        first = pred;
        printf("List reversed\n");
        display();
    }

}