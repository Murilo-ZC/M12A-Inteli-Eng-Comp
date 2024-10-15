#include <stdio.h>
#include <stdlib.h>
#define MAX_PILHA 10

typedef struct {
    int topo;
    float dados[MAX_PILHA];
}Pilha;

Pilha criarPilha(){
    Pilha p;
    p.topo = 0;
    return p;
}
Pilha inserirPilha(float valor, Pilha p){
    p.dados[p.topo] = valor;
    p.topo = p.topo + 1;
    return p;
}
Pilha retirarPilha(Pilha p, float* valor){
    p.topo = p.topo -1;
    *valor = p.dados[p.topo];
    return p;
}
void mostrarPilha(Pilha p){
    int i;
    printf("Topo da Pilha: %i\n", p.topo);
    for(i = 0; i < p.topo; i++){
        printf("Valor na posicao [%i]: %.2f\n", i, p.dados[i]);
    }
}

int main()
{
    Pilha duracell;
    duracell = criarPilha();
    duracell = inserirPilha(1.2, duracell);
    duracell = inserirPilha(2, duracell);


    //Retirar da pilha
    float valorMain;
    duracell = retirarPilha(duracell, &valorMain);
    mostrarPilha(duracell);
    return 0;
}
