#include <stdio.h>
#include <stdlib.h>

#define N 3

int main()
{
    int vetor[N];
    int i;
    for(i = 0; i < N; i++){
        printf("Informe o valor de v[%d]:", i);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < N; i++)
        printf("Valor informado em %d foi %d\n", i, vetor[i]);
    return 0;
}
