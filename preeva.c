#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = x;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to evaluate a prefix expression
int evaluatePrefix(char *prefix) {
    Stack s;
    initStack(&s);

    int length = strlen(prefix);

    // Traverse the expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        char token = prefix[i];

        // If the token is an operand, push it onto the stack
        if (isdigit(token)) {
            push(&s, token - '0'); // Convert char to int
        } 
        // If the token is an operator, pop two elements and apply the operator
        else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^') {
            int val1 = pop(&s);
            int val2 = pop(&s);

            switch (token) {
                case '+':
                    push(&s, val1 + val2);
                    break;
                case '-':
                    push(&s, val1 - val2);
                    break;
                case '*':
                    push(&s, val1 * val2);
                    break;
                case '/':
                    if (val2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(&s, val1 / val2);
                    break;
                case '^':
                    push(&s, pow(val1, val2));
                    break;
                default:
                    printf("Invalid operator: %c\n", token);
                    exit(1);
            }
        }
    }

    // The final result is the only element left in the stack
    return pop(&s);
}

int main() {
    char prefix[MAX];

    printf("Enter a prefix expression: ");
    fgets(prefix, MAX, stdin);
    prefix[strcspn(prefix, "\n")] = '\0'; // Remove trailing newline

    int result = evaluatePrefix(prefix);

    printf("Result of the prefix expression: %d\n", result);

    return 0;
}
