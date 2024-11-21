#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of a list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to partition the list
Node* partitionList(Node* head, int x) {
    if (head == NULL) return NULL;

    Node* smaller = NULL;
    Node* greater = NULL;
    Node* smallerTail = NULL;
    Node* greaterTail = NULL;

    Node* current = head;

    // Traverse the list and partition it
    while (current != NULL) {
        if (current->data < x) {
            if (smaller == NULL) {
                smaller = current;
                smallerTail = current;
            } else {
                smallerTail->next = current;
                smallerTail = current;
            }
        } else {
            if (greater == NULL) {
                greater = current;
                greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        current = current->next;
    }

    if (smallerTail != NULL) smallerTail->next = greater;
    if (greaterTail != NULL) greaterTail->next = NULL;

    return smaller ? smaller : greater;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the operations
int main() {
    Node* head = NULL;
    int choice, data, x;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Append node to list\n");
        printf("2. Partition list around value x\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                append(&head, data);
                break;

            case 2:
                printf("Enter value x to partition list: ");
                scanf("%d", &x);
                head = partitionList(head, x);
                printf("List partitioned successfully.\n");
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
