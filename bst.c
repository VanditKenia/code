#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
Node* insert(Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in the left subtree
    } else {
        root->right = insert(root->right, data);  // Insert in the right subtree
    }

    return root;
}

// Pre-order traversal (Root, Left, Right)
void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);  // Visit the root
    preOrderTraversal(root->left);  // Visit left subtree
    preOrderTraversal(root->right);  // Visit right subtree
}

// In-order traversal (Left, Root, Right)
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);  // Visit left subtree
    printf("%d ", root->data);  // Visit the root
    inOrderTraversal(root->right);  // Visit right subtree
}

// Post-order traversal (Left, Right, Root)
void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);  // Visit left subtree
    postOrderTraversal(root->right);  // Visit right subtree
    printf("%d ", root->data);  // Visit the root
}

// Function to display the tree (for testing purposes)
void display(Node* root) {
    if (root == NULL) {
        return;
    }
    display(root->left);  // Visit left subtree
    printf("%d ", root->data);  // Visit the root
    display(root->right);  // Visit right subtree
}

// Main function to test the BST
int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert node into BST\n");
        printf("2. Pre-order traversal\n");
        printf("3. In-order traversal\n");
        printf("4. Post-order traversal\n");
        printf("5. Display tree (in-order)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Pre-order traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Post-order traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Tree (in-order): ");
                display(root);
                printf("\n");
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
