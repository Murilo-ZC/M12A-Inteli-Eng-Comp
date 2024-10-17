#include <stdio.h>

#define MAX_VERTICES 5  // Define o n�mero m�ximo de v�rtices

// Estrutura do Grafo
struct Grafo {
    int adj[MAX_VERTICES][MAX_VERTICES];  // Matriz de adjac�ncia
    int numVertices;                      // N�mero de v�rtices
};

// Inicializa o Grafo
void inicializarGrafo(struct Grafo *g, int numVertices) {
    g->numVertices = numVertices;

    // Inicializa a matriz de adjac�ncia com 0 (sem arestas)
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// Adiciona uma aresta no grafo (n�o direcionado)
void adicionarAresta(struct Grafo *g, int v1, int v2) {
    if (v1 >= g->numVertices || v2 >= g->numVertices) {
        printf("Erro: V�rtices inv�lidos.\n");
    } else {
        g->adj[v1][v2] = 1;  // Aresta de v1 para v2
        g->adj[v2][v1] = 1;  // Aresta de v2 para v1 (grafo n�o direcionado)
        printf("Aresta adicionada entre %d e %d.\n", v1, v2);
    }
}

// Exibe a matriz de adjac�ncia
void exibirMatrizAdjacencia(struct Grafo *g) {
    printf("Matriz de Adjac�ncia:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Fun��o principal
int main() {
    struct Grafo g;
    inicializarGrafo(&g, MAX_VERTICES);

    adicionarAresta(&g, 0, 1);
    adicionarAresta(&g, 0, 2);
    adicionarAresta(&g, 1, 2);
    adicionarAresta(&g, 1, 3);
    adicionarAresta(&g, 3, 4);

    exibirMatrizAdjacencia(&g);

    return 0;
}
