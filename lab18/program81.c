#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phoneNumber[15];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char name[], char phoneNumber[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phoneNumber, phoneNumber);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char name[], char phone[]) {
    if (root == NULL) {
        return createNode(name, phone);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, phone);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, phone);
    }
    return root;
}


struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* search(struct Node* root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root; 
    }
    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    }
    return search(root->right, name);
}

struct Node* removeEntry(struct Node* root, char name[]) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        root->left = removeEntry(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = removeEntry(root->right, name);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);          
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phoneNumber, temp->phoneNumber);
        root->right = removeEntry(root->right, temp->name);
    }
    return root;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("Name: %s, Phone: %s\n", root->name, root->phoneNumber);
        inOrder(root->right);
    }
}

void Reverseinorder(struct Node* root) {
    if (root != NULL) {
        Reverseinorder(root->right);
        printf("Name: %s, Phone: %s\n", root->name, root->phoneNumber);
        Reverseinorder(root->left);
    }
}





int main() {
    struct Node* root = NULL;
    int choice;
    char name[50];
    char phone[15];

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add New Entry\n");
        printf("2. Remove Entry\n");
        printf("3. Search Phone Number\n");
        printf("4. List All Entries (Ascending)\n");
        printf("5. List All Entries (Descending)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                root = insert(root, name, phone);
                printf("Entry added successfully.\n");
                break;
            case 2:
                printf("Enter name to remove: ");
                scanf("%s", name);
                if (search(root, name) != NULL) {
                    root = removeEntry(root, name);
                    printf("Entry removed successfully.\n");
                } else {
                    printf("Entry not found.\n");
                }
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                struct Node* result = search(root, name);
                if (result != NULL) {
                    printf("Phone number: %s\n", result->phoneNumber);
                } else {
                    printf("Entry not found.\n");
                }
                break;
            case 4:
                printf("Phone Book Entries (Ascending Order):\n");
                inOrder(root);
                break;
            case 5:
                printf("Phone Book Entries (Descending Order):\n");
                Reverseinorder(root);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}