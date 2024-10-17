#include <stdio.h>

#define TAMANHO 10
#define VAZIO -1
#define REMOVIDO -2

// Estrutura da Tabela Hash
struct TabelaHash {
    int chaves[TAMANHO];
    int valores[TAMANHO];
};

// Função de hash simples
int funcaoHash(int chave) {
    return chave % TAMANHO;
}

// Inicializa a tabela hash
void inicializarTabela(struct TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO; i++) {
        tabela->chaves[i] = VAZIO;  // Marca todas as posições como vazias
        tabela->valores[i] = 0;     // Inicializa os valores como 0
    }
}

// Inserir chave-valor na tabela hash
void inserir(struct TabelaHash *tabela, int chave, int valor) {
    int indice = funcaoHash(chave);
    int i = 0;

    while (tabela->chaves[indice] != VAZIO && tabela->chaves[indice] != REMOVIDO) {
        indice = (indice + 1) % TAMANHO;  // Sondagem linear
        i++;
        if (i == TAMANHO) {
            printf("Tabela Hash está cheia.\n");
            return;
        }
    }

    tabela->chaves[indice] = chave;
    tabela->valores[indice] = valor;
    printf("Chave %d com valor %d inserida na posição %d.\n", chave, valor, indice);
}

// Buscar valor pela chave na tabela hash
int buscar(struct TabelaHash *tabela, int chave) {
    int indice = funcaoHash(chave);
    int i = 0;

    while (tabela->chaves[indice] != VAZIO && i < TAMANHO) {
        if (tabela->chaves[indice] == chave) {
            return tabela->valores[indice];
        }
        indice = (indice + 1) % TAMANHO;  // Sondagem linear
        i++;
    }

    printf("Chave %d não encontrada.\n", chave);
    return -1;  // Retorna -1 para chave não encontrada
}

// Remover chave da tabela hash
void remover(struct TabelaHash *tabela, int chave) {
    int indice = funcaoHash(chave);
    int i = 0;

    while (tabela->chaves[indice] != VAZIO && i < TAMANHO) {
        if (tabela->chaves[indice] == chave) {
            tabela->chaves[indice] = REMOVIDO;  // Marca como removido
            printf("Chave %d removida da posição %d.\n", chave, indice);
            return;
        }
        indice = (indice + 1) % TAMANHO;  // Sondagem linear
        i++;
    }

    printf("Chave %d não encontrada para remoção.\n", chave);
}

// Função principal para testar as operações
int main() {
    struct TabelaHash tabela;
    inicializarTabela(&tabela);

    inserir(&tabela, 10, 100);
    inserir(&tabela, 20, 200);
    inserir(&tabela, 30, 300);
    inserir(&tabela, 40, 400);
    inserir(&tabela, 50, 500);

    printf("Valor associado à chave 20: %d\n", buscar(&tabela, 20));
    printf("Valor associado à chave 30: %d\n", buscar(&tabela, 30));

    remover(&tabela, 20);
    printf("Valor associado à chave 20 após remoção: %d\n", buscar(&tabela, 20));

    return 0;
}
