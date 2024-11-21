#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node after a given position
void insertAfterPosition(Node** head, int position, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    
    if (position == 0) {
        // Insert at the beginning
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    // Traverse the list to find the position
    int count = 0;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);
        return;
    }

    // Insert after the found node
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to sort the doubly linked list
void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // List is empty or has only one node
    }

    Node* i = *head;
    Node* j = NULL;
    int tempData;

    // Bubble sort: Traverse the list and swap adjacent nodes if needed
    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                // Swap data
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
            j = j->next;
        }
        i = i->next;
    }
}

// Function to display the doubly linked list
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
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert after position\n");
        printf("2. Sort the list\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position after which to insert: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfterPosition(&head, position, data);
                break;

            case 2:
                sortList(&head);
                printf("List sorted successfully.\n");
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
