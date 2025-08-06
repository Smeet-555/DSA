#include<stdio.h>
#include<stdlib.h>

#define MAX 100
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int value){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root , int value){
    if (root == NULL)
    {
        return createnode(value);
    }

    int choice;
    printf("Where to insert %d? (1 for left, 2 for right) of node %d: ", value, root->data);
    scanf("%d", &choice);

    if (choice == 1)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

struct node* queue[MAX];
int f=0 , r = 0;

void enqueue(struct node* temp) {
    if (r >= MAX )
        printf("Queue is full\n");
    else {
        queue[r++] = temp;
    }
}

struct node* dequeue() {
    if (f == r)
        return NULL;
    return queue[f++];
}

int isQueueEmpty() {
    return (f == r);
}

void bfsTraversal(struct node *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    f = r = 0;

    enqueue(root);

    printf("BFS Traversal: ");
    while (!isQueueEmpty()) {
        struct node *current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
    printf("\n");
}


int main(){ 
    struct node *root = NULL;
    int data, choice;

    printf("Enter root node value: ");
    scanf("%d", &data);
    root = createnode(data);

    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert(root, data);

        printf("Do you want to insert more nodes? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice);

    bfsTraversal(root);
    return 0;

}