#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a term in the polynomial
typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in descending order of exponents
void insertTerm(Node** head, int coefficient, int exponent) {
    Node* newNode = createNode(coefficient, exponent);
    if (*head == NULL || (*head)->exponent < exponent) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL && temp->next->exponent > exponent) {
        temp = temp->next;
    }
    if (temp->exponent == exponent) {
        temp->coefficient += coefficient;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to display a polynomial
void displayPolynomial(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->coefficient > 0 && temp != head) {
            printf(" + ");
        }
        printf("%dx^%d", temp->coefficient, temp->exponent);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node *p1 = poly1, *p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exponent > p2->exponent) {
            insertTerm(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            insertTerm(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            int sum = p1->coefficient + p2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, p1->exponent);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Add remaining terms from both polynomials
    while (p1 != NULL) {
        insertTerm(&result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}

// Main function
int main() {
    Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n1, n2, coefficient, exponent;

    // Input first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the terms of the first polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }

    // Input second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    printf("Enter the terms of the second polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }

    // Display both polynomials
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Add the polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}
