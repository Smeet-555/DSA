#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *first1 = NULL, *tail1 = NULL;
struct node *first2 = NULL, *tail2 = NULL;
struct node *first3 = NULL, *tail3 = NULL;

struct node* createNode(int info) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = info;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

void insertNode(struct node **first1,struct node **tail1, int info) {
    struct node *newNode = createNode(info);
    if (*first1 == NULL) {
        *first1 = *tail1 = newNode;
    } else {
        (*tail1)->rptr = newNode;
        newNode->lptr = *tail1;
        *tail1 = newNode;
    }
}
void insertAtFront(struct node **first, struct node **tail, int info) {
    struct node *newNode = createNode(info);
    if (*first == NULL) {
        *first = *tail = newNode;
    } else {
        newNode->rptr = *first;
        (*first)->lptr = newNode;
        *first = newNode;
    }
}


void twoSum(){
    int carry = 0;
    while (tail1 != NULL || tail2 != NULL || carry!=0) {
        int val1 = (tail1 != NULL) ? tail1->info : 0;
        int val2 = (tail2 != NULL) ? tail2->info : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        insertNode(&first3,&tail3,sum%10);

        if (tail1 != NULL) tail1 = tail1->lptr;
        if (tail2 != NULL) tail2 = tail2->lptr;
    }
    
}
int getLength(struct node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->rptr;
    }
    return length;
}

void padWithZeroes(struct node **first, struct node **tail, int numZeroes) {
    for (int i = 0; i < numZeroes; i++) {
        insertAtFront(first, tail, 0);
    }
}
void display(struct node *first1) {
    struct node* temp = first1;
    struct node* temp2 = first3;
    struct node* prev = first3;
    struct node* temp3 = tail3;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d\t", temp->info);
        temp = temp->rptr;
    }

    printf("\n");
}
void displayResult(struct node *first1) {
    struct node* temp = first1;
    while (temp->rptr != NULL) {
        temp = temp->rptr;
    }
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d\t", temp->info);
        temp = temp->lptr;
    }
    printf("\n");
}

int main() {

    int len1 , len2;
    insertNode(&first1,&tail1, 1);
    insertNode(&first1,&tail1, 2);
    insertNode(&first1,&tail1, 3);
    insertNode(&first1,&tail1, 4);

    insertNode(&first2,&tail2, 1);
    insertNode(&first2,&tail2, 2);
    insertNode(&first2,&tail2, 3);
    insertNode(&first2,&tail2, 4);
    insertNode(&first2,&tail2, 6);
    insertNode(&first2,&tail2, 5);

    // insertNode(&first3,&tail3, 0);
    len1 = getLength(first1);
    len2 = getLength(first2);

    if (len1>len2)
    {
        padWithZeroes(&first2 ,&tail2 , len1-len2);
    }else
    {
        padWithZeroes(&first1 ,&tail1 , len2-len1);
    }

    twoSum();

    display(first1);
    display(first2);
    displayResult(first3);

    return 0;
}