#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Estrutura para representar um grafo
typedef struct {
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Função para inicializar o grafo
void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = false;
        }
    }
}

// Função para adicionar uma aresta entre dois vértices
void addEdge(Graph* graph, int u, int v) {
    if (u >= 0 && u < graph->numVertices && v >= 0 && v < graph->numVertices) {
        graph->adjMatrix[u][v] = true;
    }
}

// Função para realizar a redução transitiva de um grafo
void transitiveReduction(Graph* graph) {
    for (int k = 0; k < graph->numVertices; k++) {
        for (int i = 0; i < graph->numVertices; i++) {
            for (int j = 0; j < graph->numVertices; j++) {
                // Se existe um caminho direto de i a j e um caminho indireto via k
                // então removemos o caminho direto de i a j
                if (graph->adjMatrix[i][k] && graph->adjMatrix[k][j]) {
                    graph->adjMatrix[i][j] = false;
                }
            }
        }
    }
}

// Função para imprimir o grafo
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Exemplo de uso do algoritmo
    Graph graph;
    int numVertices = 4;
    
    initializeGraph(&graph, numVertices);
    
    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 0, 3);
    
    printf("Grafo original:\n");
    printGraph(&graph);
    
    transitiveReduction(&graph);
    
    printf("Grafo após a redução transitiva:\n");
    printGraph(&graph);
    
    return 0;
}