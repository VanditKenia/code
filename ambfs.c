#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform BFS traversal
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int start, int n) {
    int visited[MAX_VERTICES] = {0};  // Array to track visited nodes
    int queue[MAX_VERTICES];  // Queue for BFS
    int front = 0, rear = 0;  // Queue pointers

    // Enqueue the start node
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal starting from node %d: ", start);

    while (front < rear) {
        // Dequeue a node
        int currentNode = queue[front++];

        printf("%d ", currentNode);  // Visit the node

        // Enqueue all unvisited adjacent nodes
        for (int i = 0; i < n; i++) {
            if (graph[currentNode][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// Function to input the graph's adjacency matrix
void inputGraph(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Function to display the graph's adjacency matrix
void displayGraph(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    printf("Adjacency Matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize the graph's adjacency matrix to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    inputGraph(graph, n);

    // Display the adjacency matrix
    displayGraph(graph, n);

    // Get the starting node for BFS
    printf("Enter the starting node for BFS (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Perform BFS traversal
    BFS(graph, start, n);

    return 0;
}
