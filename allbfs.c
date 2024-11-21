#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph using an adjacency list
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with `n` vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    // Allocate memory for adjacency list
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    
    // Initialize each adjacency list as NULL
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

// Function to add an edge to the graph (undirected graph)
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // Add an edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to perform BFS traversal
void BFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};  // Array to keep track of visited vertices
    int queue[MAX_VERTICES];  // Queue to manage BFS traversal
    int front = 0, rear = 0;  // Queue pointers

    // Enqueue the start vertex
    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    printf("BFS Traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        // Dequeue a vertex from the queue
        int currentVertex = queue[front++];

        printf("%d ", currentVertex);  // Print the current vertex

        // Explore all adjacent vertices of the current vertex
        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            // If the adjacent vertex has not been visited, enqueue it
            if (!visited[adjVertex]) {
                queue[rear++] = adjVertex;
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

// Function to display the adjacency list of the graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    int vertices, edges, src, dest, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Create a graph with the given number of vertices
    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Add edges to the graph
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Display the adjacency list representation of the graph
    displayGraph(graph);

    // Perform BFS traversal from a given start vertex
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(graph, startVertex);

    return 0;
}
