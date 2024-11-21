#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];       // Array to store queue elements
    int front[MAX];     // Array to store the front indices of each queue
    int rear[MAX];      // Array to store the rear indices of each queue
    int next[MAX];      // Array to store the next free index for each position
    int free;           // The start of the free list
    int k;              // Number of queues
} kQueues;

// Initialize kQueues
void initKQueues(kQueues *kq, int k) {
    kq->k = k;
    kq->free = 0;

    for (int i = 0; i < MAX - 1; i++) {
        kq->next[i] = i + 1; // Link all indices for free list
    }
    kq->next[MAX - 1] = -1; // End of free list

    for (int i = 0; i < k; i++) {
        kq->front[i] = -1; // No elements in any queue initially
        kq->rear[i] = -1;
    }
}

// Check if a specific queue is empty
bool isQueueEmpty(kQueues *kq, int qn) {
    return kq->front[qn] == -1;
}

// Check if the overall array is full
bool isFull(kQueues *kq) {
    return kq->free == -1;
}

// Enqueue an element to a specific queue
void enqueue(kQueues *kq, int x, int qn) {
    if (isFull(kq)) {
        printf("Queue overflow\n");
        return;
    }

    int i = kq->free; // Get the first free index
    kq->free = kq->next[i]; // Update free index to the next in free list

    if (isQueueEmpty(kq, qn)) {
        kq->front[qn] = i; // First element in the queue
    } else {
        kq->next[kq->rear[qn]] = i; // Link the new element to the previous rear
    }

    kq->next[i] = -1;       // Mark the next of the new element as -1
    kq->rear[qn] = i;       // Update the rear of the queue
    kq->arr[i] = x;         // Store the element
}

// Dequeue an element from a specific queue
int dequeue(kQueues *kq, int qn) {
    if (isQueueEmpty(kq, qn)) {
        printf("Queue underflow\n");
        return -1;
    }

    int i = kq->front[qn]; // Get the front index of the queue
    kq->front[qn] = kq->next[i]; // Update the front to the next element

    if (kq->front[qn] == -1) { // If the queue becomes empty
        kq->rear[qn] = -1;
    }

    kq->next[i] = kq->free; // Add the removed index to the free list
    kq->free = i;

    return kq->arr[i];
}

// Display the elements of a specific queue
void displayq(kQueues *kq, int qn) {
    if (isQueueEmpty(kq, qn)) {
        printf("Queue %d is empty\n", qn);
        return;
    }

    printf("Queue %d: ", qn);
    int i = kq->front[qn];
    while (i != -1) {
        printf("%d ", kq->arr[i]);
        i = kq->next[i];
    }
    printf("\n");
}

// Display all the queues
void displayAll(kQueues *kq) {
    for (int i = 0; i < kq->k; i++) {
        displayq(kq, i);
    }
}

int main() {
    int k, choice, x, qn;

    printf("Enter the number of queues: ");
    scanf("%d", &k);

    kQueues kq;
    initKQueues(&kq, k);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Display All Queues\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter queue number (0 to %d): ", k - 1);
                scanf("%d", &qn);
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(&kq, x, qn);
                break;

            case 2:
                printf("Enter queue number (0 to %d): ", k - 1);
                scanf("%d", &qn);
                x = dequeue(&kq, qn);
                if (x != -1) {
                    printf("Dequeued element: %d\n", x);
                }
                break;

            case 3:
                printf("Enter queue number (0 to %d): ", k - 1);
                scanf("%d", &qn);
                displayq(&kq, qn);
                break;

            case 4:
                displayAll(&kq);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
