#include <stdio.h>
#include <stdlib.h>

// Estrutura do n� da �rvore
struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
};

// Fun��o para criar um novo n�
struct No* novoNo(int valor) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

// Fun��o para inserir um novo n� na �rvore bin�ria de busca
struct No* inserir(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);  // Se a raiz for nula, insere o primeiro n�
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);  // Inserir na sub�rvore esquerda
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);  // Inserir na sub�rvore direita
    }

    return raiz;
}

// Fun��o para buscar um valor na �rvore
struct No* buscar(struct No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;  // Retorna o n� encontrado ou NULL se n�o encontrado
    }

    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);  // Buscar na sub�rvore esquerda
    } else {
        return buscar(raiz->direita, valor);  // Buscar na sub�rvore direita
    }
}

// Fun��o auxiliar para encontrar o n� de menor valor (usada na remo��o)
struct No* menorValor(struct No* no) {
    struct No* atual = no;

    // Percorre at� encontrar o n� mais � esquerda (menor valor)
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual;
}

// Fun��o para remover um n� da �rvore
struct No* remover(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);  // Remover na sub�rvore esquerda
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);  // Remover na sub�rvore direita
    } else {
        // N� com apenas um filho ou nenhum
        if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // N� com dois filhos: obt�m o sucessor (menor n� na sub�rvore direita)
        struct No* temp = menorValor(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);  // Remove o sucessor
    }

    return raiz;
}

// Fun��o para percorrer a �rvore em ordem (in-order traversal)
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);  // Visita a sub�rvore esquerda
        printf("%d ", raiz->valor);  // Visita a raiz
        emOrdem(raiz->direita);  // Visita a sub�rvore direita
    }
}

// Fun��o principal
int main() {
    struct No* raiz = NULL;

    // Inserindo elementos na �rvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Percurso em ordem da �rvore: ");
    emOrdem(raiz);
    printf("\n");

    // Buscando um valor
    int valor = 40;
    struct No* resultado = buscar(raiz, valor);
    if (resultado != NULL) {
        printf("Valor %d encontrado na �rvore.\n", valor);
    } else {
        printf("Valor %d n�o encontrado na �rvore.\n", valor);
    }

    // Removendo um valor
    raiz = remover(raiz, 20);
    printf("�rvore ap�s remover 20: ");
    emOrdem(raiz);
    printf("\n");

    raiz = remover(raiz, 30);
    printf("�rvore ap�s remover 30: ");
    emOrdem(raiz);
    printf("\n");

    raiz = remover(raiz, 50);
    printf("�rvore ap�s remover 50: ");
    emOrdem(raiz);
    printf("\n");

    return 0;
}
