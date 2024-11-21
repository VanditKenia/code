#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to find the length of the linked list
int getLength(struct ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to rotate the linked list by k places
struct ListNode* rotateList(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    // Get the length of the list
    int length = getLength(head);

    // Normalize k to handle cases where k is larger than the length of the list
    k = k % length;
    if (k == 0) {
        return head;  // No rotation needed
    }

    // Traverse to the (length - k)th node
    struct ListNode* current = head;
    for (int i = 1; i < length - k; i++) {
        current = current->next;
    }

    // current is now at the (length - k)th node, which will be the new tail
    struct ListNode* newHead = current->next;  // The new head of the rotated list
    current->next = NULL;  // Break the list to form two parts

    // Traverse to the last node and connect it to the original head
    struct ListNode* last = newHead;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = head;

    return newHead;  // Return the new head of the list
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
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Main function to test the implementation
int main() {
    // Create a linked list: 1 → 2 → 3 → 4 → 5
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original List: ");
    printList(head);

    // Rotate the list by k places
    int k = 2;
    struct ListNode* rotatedList = rotateList(head, k);

    printf("List after rotating by %d places: ", k);
    printList(rotatedList);

    return 0;
}

