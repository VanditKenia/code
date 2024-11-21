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

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to concatenate two lists
void concatenateLists(Node** head1, Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }

    // Traverse to the last node of the first list
    Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the last node of the first list to the head of the second list
    temp->next = *head2;
    if (*head2 != NULL) {
        (*head2)->prev = temp;
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
    Node* list1 = NULL;
    Node* list2 = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at end of list 1\n");
        printf("2. Insert at end of list 2\n");
        printf("3. Concatenate list 1 and list 2\n");
        printf("4. Display list 1\n");
        printf("5. Display list 2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert into list 1: ");
                scanf("%d", &data);
                insertAtEnd(&list1, data);
                break;

            case 2:
                printf("Enter data to insert into list 2: ");
                scanf("%d", &data);
                insertAtEnd(&list2, data);
                break;

            case 3:
                concatenateLists(&list1, &list2);
                printf("Lists concatenated successfully.\n");
                break;

            case 4:
                displayList(list1);
                break;

            case 5:
                displayList(list2);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
