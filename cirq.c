#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // Maximum size of the queue

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size; // Keeps track of the number of elements
} CircularQueue;

// Initialize the queue
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

// Check if the queue is empty
int isEmpty(CircularQueue *q) {
    return q->size == 0;
}

// Check if the queue is full
int isFull(CircularQueue *q) {
    return q->size == MAX;
}

// Enqueue an element into the queue
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) { // First element being added
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX; // Circular increment
    q->arr[q->rear] = value;
    q->size++;
    printf("Enqueued: %d\n", value);
}

// Dequeue an element from the queue
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->arr[q->front];
    q->front = (q->front + 1) % MAX; // Circular increment
    q->size--;
    if (q->size == 0) { // Reset front and rear for empty queue
        q->front = -1;
        q->rear = -1;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Get the front element of the queue
int front(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

// Get the rear element of the queue
int rear(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->rear];
}

// Main function to demonstrate the operations
int main() {
    CircularQueue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Is Empty\n4. Is Full\n5. Front\n6. Rear\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                printf("Queue is %s\n", isEmpty(&q) ? "empty" : "not empty");
                break;

            case 4:
                printf("Queue is %s\n", isFull(&q) ? "full" : "not full");
                break;

            case 5:
                value = front(&q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;

            case 6:
                value = rear(&q);
                if (value != -1) {
                    printf("Rear element: %d\n", value);
                }
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
