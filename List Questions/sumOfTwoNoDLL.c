#include <stdio.h>
#include <stdlib.h>

// Node structure

struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};

// Head and tail pointers for 3 linked lists
struct node *head1 = NULL, *tail1 = NULL;
struct node *head2 = NULL, *tail2 = NULL;
struct node *head3 = NULL, *tail3 = NULL;

// Insert into List 1
void insertNodeList1(int info) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->info = info;
    newnode->lptr = NULL;
    newnode->rptr = NULL;

    if (head1 == NULL) {
        head1 = tail1 = newnode;
    } else {
        tail1->rptr = newnode;
        newnode->lptr = tail1;
        tail1 = newnode;
    }
}

// Insert into List 2
void insertNodeList2(int info) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->info = info;
    newnode->lptr = NULL;
    newnode->rptr = NULL;

    if (head2 == NULL) {
        head2 = tail2 = newnode;
    } else {
        tail2->rptr = newnode;
        newnode->lptr = tail2;
        tail2 = newnode;
    }
}

// Insert into List 3
void insertNodeList3() {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->info = 0;
    newnode->lptr = NULL;
    newnode->rptr = NULL;

    if (head3 == NULL) {
        head3 = tail3 = newnode;
    } else {
        tail3->rptr = newnode;
        newnode->lptr = tail3;
        tail3 = newnode;
    }
}

void sumNode(){
    int rem =0 , sum = 0 , val=0;
    while (tail3 != NULL )
    {
        sum = tail1->info + tail2->info + val;
        if (sum>9)
        {
            if (tail3 == head3)
            {
                tail3->info = sum;
                break;
            }
                tail3->info = sum % 10;
                val = sum / 10;
                // val = 0;
                // sum = 0;
        }
        else{
            tail3->info = sum;
        }
        tail3 = tail3->lptr;
        tail1 = tail1->lptr;
        tail2 = tail2->lptr;
    }
    

    
}

// Print any list
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->rptr;
    }
    printf("\n");
}

int main() {
    // Inserting dynamically into all 3 lists
    insertNodeList1(4);
    insertNodeList1(5);
    insertNodeList1(9);

    insertNodeList2(7);
    insertNodeList2(8);
    insertNodeList2(8);

    // insertNodeList3(15);
    // insertNodeList3(25);
    // insertNodeList3(35);
    insertNodeList3();
    insertNodeList3();
    insertNodeList3();

    sumNode();
    // Printing all 3 lists
    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    printf("List 3: ");
    printList(head3);

    return 0;
}
