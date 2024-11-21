#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse the linked list
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to add two linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Reverse both lists
    l1 = reverse(l1);
    l2 = reverse(l2);

    struct ListNode* result = NULL;  // Result list
    struct ListNode* temp = NULL;
    int carry = 0;

    // Add corresponding digits
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        // Add l1 digit
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        // Add l2 digit
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Compute carry and the digit to store in the result
        carry = sum / 10;
        sum = sum % 10;

        // Create a new node for the sum digit
        struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
        newNode->val = sum;
        newNode->next = NULL;

        // Append the new node to the result list
        if (result == NULL) {
            result = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    // Reverse the result list to restore the correct order
    return reverse(result);
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
    // Create two linked lists representing the numbers
    struct ListNode* operand_1 = newNode(7);
    operand_1->next = newNode(2);
    operand_1->next->next = newNode(3);
    operand_1->next->next->next = newNode(3);

    struct ListNode* operand_2 = newNode(5);
    operand_2->next = newNode(7);
    operand_2->next->next = newNode(4);

    // Add the two numbers
    struct ListNode* result = addTwoNumbers(operand_1, operand_2);

    // Print the result
    printf("Result: ");
    printList(result);

    return 0;
}
