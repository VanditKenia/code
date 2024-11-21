#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    char items[MAX];
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
void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = c;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to peek at the top element of the stack
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to convert infix expression to prefix
void infixToPrefix(char *infix, char *prefix) {
    Stack s;
    initStack(&s);

    // Reverse the infix expression
    reverseString(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        // If the token is an operand, add it to the prefix expression
        if (isalnum(token)) {
            prefix[j++] = token;
        } 
        // If the token is '(', push it onto the stack
        else if (token == '(') {
            push(&s, token);
        } 
        // If the token is ')', pop and output from the stack until '(' is found
        else if (token == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                prefix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) == '(') {
                pop(&s); // Remove '(' from the stack
            }
        } 
        // If the token is an operator
        else if (isOperator(token)) {
            while (!isEmpty(&s) && precedence(peek(&s)) > precedence(token)) {
                prefix[j++] = pop(&s);
            }
            push(&s, token);
        }
    }

    // Pop all the remaining operators from the stack
    while (!isEmpty(&s)) {
        prefix[j++] = pop(&s);
    }

    prefix[j] = '\0'; // Null-terminate the prefix expression

    // Reverse the prefix expression to get the final result
    reverseString(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove trailing newline

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
