#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
};

// Função para criar um novo nó
struct No* novoNo(int valor) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

// Função para inserir um novo nó na árvore binária de busca
struct No* inserir(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);  // Se a raiz for nula, insere o primeiro nó
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);  // Inserir na subárvore esquerda
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);  // Inserir na subárvore direita
    }

    return raiz;
}

// Função para buscar um valor na árvore
struct No* buscar(struct No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;  // Retorna o nó encontrado ou NULL se não encontrado
    }

    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);  // Buscar na subárvore esquerda
    } else {
        return buscar(raiz->direita, valor);  // Buscar na subárvore direita
    }
}

// Função auxiliar para encontrar o nó de menor valor (usada na remoção)
struct No* menorValor(struct No* no) {
    struct No* atual = no;

    // Percorre até encontrar o nó mais à esquerda (menor valor)
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual;
}

// Função para remover um nó da árvore
struct No* remover(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);  // Remover na subárvore esquerda
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);  // Remover na subárvore direita
    } else {
        // Nó com apenas um filho ou nenhum
        if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Nó com dois filhos: obtém o sucessor (menor nó na subárvore direita)
        struct No* temp = menorValor(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);  // Remove o sucessor
    }

    return raiz;
}

// Função para percorrer a árvore em ordem (in-order traversal)
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);  // Visita a subárvore esquerda
        printf("%d ", raiz->valor);  // Visita a raiz
        emOrdem(raiz->direita);  // Visita a subárvore direita
    }
}

// Função principal
int main() {
    struct No* raiz = NULL;

    // Inserindo elementos na árvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Percurso em ordem da árvore: ");
    emOrdem(raiz);
    printf("\n");

    // Buscando um valor
    int valor = 40;
    struct No* resultado = buscar(raiz, valor);
    if (resultado != NULL) {
        printf("Valor %d encontrado na árvore.\n", valor);
    } else {
        printf("Valor %d não encontrado na árvore.\n", valor);
    }

    // Removendo um valor
    raiz = remover(raiz, 20);
    printf("Árvore após remover 20: ");
    emOrdem(raiz);
    printf("\n");

    raiz = remover(raiz, 30);
    printf("Árvore após remover 30: ");
    emOrdem(raiz);
    printf("\n");

    raiz = remover(raiz, 50);
    printf("Árvore após remover 50: ");
    emOrdem(raiz);
    printf("\n");

    return 0;
}
