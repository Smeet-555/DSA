#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

// Function prototypes
void insertAtLast(int data);
void display();
int countNodes();
void swapKthNode(int k);

int main() {
    int n, data, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtLast(data);
    }

    printf("Original list:\n");
    display();

    printf("Enter K to swap Kth node from start and end: ");
    scanf("%d", &k);

    swapKthNode(k);

    printf("List after swapping:\n");
    display();

    return 0;
}

void insertAtLast(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = data;
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

void display() {
    struct node *temp = first;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

int countNodes() {
    int count = 0;
    struct node *temp = first;
    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    return count;
}

void swapKthNode(int k) {
    int n = countNodes();

    // Check if k is valid
    if (k > n || k <= 0) {
        printf("Invalid value of k.\n");
        return;
    }

    // If kth node from start and end are same node (middle node in odd length), no need to swap
    if (2*k - 1 == n) {
        printf("Kth node from beginning and end are the same. No swap needed.\n");
        return;
    }

    struct node *x_prev = NULL;
    struct node *x = first;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->link;
    }

    struct node *y_prev = NULL;
    struct node *y = first;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->link;
    }

    // If x_prev exists, link it to y
    if (x_prev != NULL)
        x_prev->link = y;
    else // x is head
        first = y;

    // If y_prev exists, link it to x
    if (y_prev != NULL)
        y_prev->link = x;
    else // y is head
        first = x;

    // Swap next pointers
    struct node *temp = x->link;
    x->link = y->link;
    y->link = temp;
}
