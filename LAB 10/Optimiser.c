#include <stdio.h>
#include <stdlib.h>

// Node definition
struct node {
    char info;
    struct node *link;
};

struct node *first = NULL;

// Function declarations
char getData();
int countNodes();
void insertAtFirst();
void insertAtLast();
void deleteData();
void insertIntoOrderedList();
void display();
void sortList();
void reverseList();

int main() {
    int key;

    do {
        printf("\n-----------------------------------------\n");
        printf("Total nodes in LinkedList: %d\n", countNodes());
        printf("0 - Exit\n");
        printf("1 - Insert at first\n");
        printf("2 - Insert at last\n");
        printf("3 - Delete data\n");
        printf("4 - Insert into ordered list\n");
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
            default: printf("Invalid input\n");
        }
    } while (key != 0);

    return 0;
}

char getData() {
    char x;
    printf("Enter info (character): ");
    scanf(" %c", &x);  // space before %c to consume any newline
    return x;
}

int countNodes() {
    int count = 0;
    struct node *save = first;
    while (save != NULL) {
        count++;
        save = save->link;
    }
    return count;
}

void insertAtFirst() {
    int num;
    printf("Insert at First - Enter number of nodes: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        char x = getData();
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            return;
        }
        newNode->info = x;
        newNode->link = first;
        first = newNode;
    }
}

void insertAtLast() {
    int num;
    printf("Insert at Last - Enter number of nodes: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        char x = getData();
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            return;
        }
        newNode->info = x;
        newNode->link = NULL;

        if (first == NULL) {
            first = newNode;
        } else {
            struct node *temp = first;
            while (temp->link != NULL)
                temp = temp->link;
            temp->link = newNode;
        }
    }
}

void deleteData() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    int num;
    printf("Delete Nodes - Enter number of nodes: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        char x = getData();
        struct node *temp = first;
        struct node *prev = NULL;

        while (temp != NULL && temp->info != x) {
            prev = temp;
            temp = temp->link;
        }

        if (temp == NULL) {
            printf("Data '%c' not found\n", x);
        } else {
            if (prev == NULL) {  // Deleting first node
                first = temp->link;
            } else {
                prev->link = temp->link;
            }
            free(temp);
            printf("Deleted '%c'\n", x);
        }
    }
}

void insertIntoOrderedList() {
    int num;
    printf("Insert into Ordered List - Enter number of nodes: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        char x = getData();
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            return;
        }
        newNode->info = x;
        newNode->link = NULL;

        if (first == NULL || x < first->info) {
            newNode->link = first;
            first = newNode;
        } else {
            struct node *temp = first;
            while (temp->link != NULL && temp->link->info < x)
                temp = temp->link;
            newNode->link = temp->link;
            temp->link = newNode;
        }
    }
}

void display() {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct node *temp = first;
    printf("List: ");
    while (temp != NULL) {
        printf("[info: %c] -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

void sortList() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *i, *j;
    for (i = first; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->info > j->info) {
                char temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }

    printf("List sorted in ascending order.\n");
    display();
}

void reverseList() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *prev = NULL, *curr = first, *next = NULL;

    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }

    first = prev;
    printf("List reversed.\n");
    display();
}
