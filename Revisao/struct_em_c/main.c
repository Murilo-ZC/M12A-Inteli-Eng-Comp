#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
typedef struct {
    char nome[MAX];
    float nota;
    int haveNotebook;
} Aluno;

int main()
{
    Aluno joelison;
    strcat(joelison.nome,"Joelison");
    joelison.nota = 5.0;
    joelison.nome[4] = '\0';
    printf("%s", joelison.nome);
    return 0;
}
