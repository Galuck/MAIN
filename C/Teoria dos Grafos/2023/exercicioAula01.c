#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void addEdge(int adjacencyMatrix[][MAX_VERTICES], int v1, int v2) {
    adjacencyMatrix[v1][v2] = 1;
    adjacencyMatrix[v2][v1] = 1;
}

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdgeToList(Node* adjacencyList[], int v1, int v2) {
    Node* newNode = createNode(v2);
    newNode->next = adjacencyList[v1];
    adjacencyList[v1] = newNode;

    newNode = createNode(v1);
    newNode->next = adjacencyList[v2];
    adjacencyList[v2] = newNode;
}

void printMatrix(int adjacencyMatrix[][MAX_VERTICES], int vertices) {
    printf("Matriz de Adjacência:\n");
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void printList(Node* adjacencyList[], int vertices) {
    printf("\nLista de Adjacência:\n");
    for (int i = 1; i <= vertices; i++) {
        printf("%d: ", i);
        Node* current = adjacencyList[i];
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Digite o número de pares de valores: ");
    scanf("%d", &N);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    Node* adjacencyList[MAX_VERTICES] = {NULL};

    for (int i = 0; i < N; i++) {
        int v1, v2;
        printf("Digite o par de valores %d (v1 v2): ", i + 1);
        scanf("%d %d", &v1, &v2);
        addEdge(adjacencyMatrix, v1, v2);
        addEdgeToList(adjacencyList, v1, v2);
    }

    int maxVertex = 0;
    for (int i = 0; i < N; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        maxVertex = (v1 > maxVertex) ? v1 : maxVertex;
        maxVertex = (v2 > maxVertex) ? v2 : maxVertex;
        addEdge(adjacencyMatrix, v1, v2);
        addEdgeToList(adjacencyList, v1, v2);
    }

    printMatrix(adjacencyMatrix, maxVertex);
    printList(adjacencyList, maxVertex);

    return 0;
}
