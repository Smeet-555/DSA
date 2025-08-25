#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

int search(struct Node* root, int x)
{
    if (root == NULL)
        return 0;

    if (root->data == x)
        return 1;
    else if (x < root->data)
        return search(root->left, x);
    else
        return search(root->right, x);
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
} 

struct Node *valueNode(struct Node *root){
    struct Node * temp = root;
    while (temp->left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
}
struct Node *deleteNode(struct Node *root , int value){
    struct Node *temp;
    if (root == NULL){
        return root;
    }
    if (value < root->data)
    {
        root -> left = deleteNode(root->left , value);
    }
    else if (value > root->data)
    {
        root -> right = deleteNode(root->right , value);
            
    }

    else{
        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        else{
            temp = valueNode(root->right);
            root->data  = temp->data;
            // root->right = deleteNode(root->right , temp->right);
            root->right = deleteNode(root->right , temp->data);

        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int data, choice;
    // int searchValue;

    printf("Enter root node value: ");
    scanf("%d", &data);
    root = createNode(data);

    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert(root, data);

        printf("Do you want to insert more nodes? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice);

    printf("------------ TRAVERSAL BEFORE DELETION --------------------");

    printf("\nInorder Traversal of Tree: ");
    inorder(root);
    printf("\n----------------------------------------");

    printf("\nPreorder Traversal of Tree: ");
    preorder(root);
    printf("\n----------------------------------------");

    printf("\nPostorder Traversal of Tree: ");
    postorder(root);
    printf("\n----------------------------------------");

    int searchChoice = 1;
    do {
        int searchValue;
        printf("\nEnter the value to search in the tree: ");
        scanf("%d", &searchValue);

        if (search(root, searchValue))
            printf("%d is found in the tree.\n", searchValue);
        else
            printf("%d is not found in the tree.\n", searchValue);

        printf("Do you want to search more nodes? (1 for Yes / 0 for No): ");
        scanf("%d", &searchChoice);  
    } while (searchChoice != 0);


        int deleteChoice = 1;
    do {
        int deleteValue;
        printf("\nEnter the value to delete from the tree: ");
        scanf("%d", &deleteValue);

        if (search(root, deleteValue))
            // printf("%d is found in the tree.\n", searchValue);
            deleteNode(root , deleteValue);
        else
            printf("%d is not found in the tree.\n", deleteValue);

        printf("Do you want to delete more nodes? (1 for Yes / 0 for No): ");
        scanf("%d", &deleteChoice);  
    } while (deleteChoice != 0);

        printf("------------ TRAVERSAL AFTER DELETION --------------------");
        
    printf("\nInorder Traversal of Tree: ");
    inorder(root);
    printf("\n----------------------------------------");

    printf("\nPreorder Traversal of Tree: ");
    preorder(root);
    printf("\n----------------------------------------");

    printf("\nPostorder Traversal of Tree: ");
    postorder(root);
    printf("\n----------------------------------------");



    return 0;
}
