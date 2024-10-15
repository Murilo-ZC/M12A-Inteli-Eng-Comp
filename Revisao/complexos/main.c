#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float img;
} Complexo;

Complexo criarComplexo(float real, float img){
    Complexo n;
    n.real = real;
    n.img = img;
    return n;
}

void mostrarComplexo(Complexo n){
    printf("%.2f+%.2fi", n.real, n.img);
}

Complexo somarComplexo(Complexo n1, Complexo n2){
    return criarComplexo(n1.real+n2.real,
                         n1.img+n2.img);
}

int main()
{
    Complexo inteli;
    inteli = criarComplexo(10,5);
    mostrarComplexo(inteli);
    return 0;
}
