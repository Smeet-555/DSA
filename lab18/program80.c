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

void inorder(struct Node* root, int arr[], int *index) {
    if (root == NULL)
        return;

    inorder(root->left, arr, index);
    arr[(*index)++] = root->data;   
    inorder(root->right, arr, index);
}

int main() {
    struct Node* root = NULL;
    int data, choice , arr[100] , index = 0;

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

    inorder(root , arr , &index);

    printf("\nInorder Traversal in array: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nThe minimum element in the BST is: %d" , arr[0]);
    printf("\nThe maximum element in the BST is: %d" , arr[index - 1]);

    return 0;
}
