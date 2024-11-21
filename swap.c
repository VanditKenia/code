#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to swap nodes in pairs
struct ListNode* swapPairs(struct ListNode* head) {
    // If the list is empty or has only one node, no swap is needed
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* current = dummy;

    // Iterate through the list in pairs
    while (current->next != NULL && current->next->next != NULL) {
        struct ListNode* first = current->next;
        struct ListNode* second = current->next->next;
        
        // Swap the nodes
        first->next = second->next;
        second->next = first;
        current->next = second;

        // Move to the next pair
        current = first;
    }

    return dummy->next;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Main function to test the implementation
int main() {
    // Create a linked list: 1 → 2 → 3 → 4
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    printf("Original List: ");
    printList(head);

    // Swap nodes in pairs
    struct ListNode* swappedList = swapPairs(head);

    printf("List after swapping nodes in pairs: ");
    printList(swappedList);

    return 0;
}
