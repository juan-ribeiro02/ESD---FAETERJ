#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Altura.h"

int main()
{
    tAltura *juanAltura, *juanNovaAltura;
    int comp;

    juanAltura = altura_cria(175, 1.75);

    altura_exibe(juanAltura);

    juanNovaAltura = altura_copia(juanAltura);

    altura_exibe(juanNovaAltura);

    comp = altura_compara(juanAltura, juanNovaAltura);

    printf("%d", comp);

    altura_soma(juanNovaAltura, 10);

    altura_exibe(juanNovaAltura);

    free(juanAltura);

    return 0;
}