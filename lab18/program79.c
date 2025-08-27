#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* constructBST(int pre[], int post[], int *preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h) return NULL;

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = pre[(*preIndex)++];
    root->left = root->right = NULL;

    if (l == h || *preIndex >= size) return root;

    int i;
    for (i = l; i <= h; i++)
        if (post[i] == pre[*preIndex]) break;

    if (i <= h) {
        root->left  = constructBST(pre, post, preIndex, l, i, size);
        root->right = constructBST(pre, post, preIndex, i+1, h-1, size);
    }
    return root;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int pre[]  = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre)/sizeof(pre[0]);
    int preIndex = 0;

    struct Node* root = constructBST(pre, post, &preIndex, 0, size-1, size);

    inorder(root);
    return 0;
}