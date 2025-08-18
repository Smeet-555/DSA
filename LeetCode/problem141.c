#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          
        fast = fast->next->next;     

        if (slow == fast) {
            return true;             
        }
    }
    return false; 
}

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    // Example 1: Linked list with a cycle
    struct ListNode* head1 = newNode(3);
    struct ListNode* second = newNode(2);
    struct ListNode* third = newNode(0);
    struct ListNode* fourth = newNode(-4);

    head1->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; 

    if (hasCycle(head1)) {
        printf("Cycle detected in list 1 \n");
    } else {
        printf("No cycle in list 1 \n");
    }

    struct ListNode* head2 = newNode(1);
    head2->next = newNode(2);

    if (hasCycle(head2)) {
        printf("Cycle detected in list 2 \n");
    } else {
        printf("No cycle in list 2 \n");
    }

    return 0;
}
