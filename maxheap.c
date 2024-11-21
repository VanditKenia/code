#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain the heap property
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child is larger than root or left child
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Extract the maximum element (root) from the heap
int extractMax(int arr[], int *n) {
    if (*n <= 0) {
        return -1;  // Heap is empty
    }

    if (*n == 1) {
        (*n)--;
        return arr[0];  // Only one element, return it
    }

    // Store the maximum value (root) to return
    int root = arr[0];

    // Replace the root with the last element
    arr[0] = arr[*n - 1];
    (*n)--;  // Reduce the size of the heap

    // Heapify the root to maintain heap property
    heapify(arr, *n, 0);

    return root;
}

// Function to build the Max Heap from an array
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and call heapify for each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// HeapSort function
void heapSort(int arr[], int n) {
    // Build a Max Heap
    buildMaxHeap(arr, n);

    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Build the Max Heap
    buildMaxHeap(arr, n);
    printf("Max Heap: ");
    printArray(arr, n);

    // Extract maximum element from the heap
    int max = extractMax(arr, &n);
    printf("Extracted Max: %d\n", max);
    printf("Heap after extraction: ");
    printArray(arr, n);

    // Sort the array using heap sort
    heapSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

