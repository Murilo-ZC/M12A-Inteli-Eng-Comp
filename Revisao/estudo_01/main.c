#include <stdio.h>
#include <stdlib.h>

//Prototipo de funcao
int acha_maior(int, int);

int main()
{
    int valor1 = 10, valor2 = 10;
    printf("Resultado: %i\n", acha_maior(valor1,valor2));
    int v = 5;
    int* vp;
    vp = &v;
    *vp = 6;
    printf("%p\n", vp);
    printf("%p\n", &v);
    printf("%p\n", &vp);
    return 0;
}

int acha_maior(int n1, int n2){
    if(n1>n2){
        return -1;
    }else if(n2>n1){
        return 1;
    }else{
        return 0;
    }
}
