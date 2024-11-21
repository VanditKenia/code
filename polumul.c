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

// Function to insert a term into a polynomial in descending order of exponents
void insertTerm(Node** head, int coefficient, int exponent) {
    if (coefficient == 0) return; // Skip zero coefficients

    Node* newNode = createNode(coefficient, exponent);
    
    // If list is empty or new node's exponent is greater than the head node's exponent
    if (*head == NULL || (*head)->exponent < exponent) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to find the correct position
    Node* temp = *head;
    while (temp->next != NULL && temp->next->exponent > exponent) {
        temp = temp->next;
    }

    // If same exponent is found, combine the coefficients
    if (temp->exponent == exponent) {
        temp->coefficient += coefficient;
        if (temp->coefficient == 0) { // Remove the term if coefficient becomes 0
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
        }
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

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;

    for (Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coeff = p1->coefficient * p2->coefficient;
            int exp = p1->exponent + p2->exponent;
            insertTerm(&result, coeff, exp);  // Insert terms and combine like terms
        }
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

    // Multiply the polynomials
    result = multiplyPolynomials(poly1, poly2);

    // Display the result
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}
