#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform DFS traversal using recursion
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int visited[MAX_VERTICES], int numVertices) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);  // Print the current vertex

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < numVertices; i++) {
        // If there's an edge from vertex to i and i is not visited
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited, numVertices);
        }
    }
}

// Function to input the graph's adjacency matrix
void inputGraph(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Function to display the graph's adjacency matrix
void displayGraph(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Adjacency Matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};  // Array to track visited nodes
    int numVertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Initialize the graph's adjacency matrix to 0
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    inputGraph(graph, numVertices);

    // Display the adjacency matrix
    displayGraph(graph, numVertices);

    // Get the starting node for DFS
    printf("Enter the starting node for DFS (0 to %d): ", numVertices - 1);
    scanf("%d", &startVertex);

    // Perform DFS traversal
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS(graph, startVertex, visited, numVertices);

    printf("\n");

    return 0;
}
