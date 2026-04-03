#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Altura.h"

struct altura{
    float cm, m;
};

tAltura * altura_cria(float cm, float m)
{
    tAltura *altura = (tAltura*)malloc(sizeof(tAltura));

    if(altura == NULL)
    {
        printf("MEMORIA INSUFICIENTE!\n");
        exit(1);
    }

    altura->cm = cm;
    altura->m = m;

    return altura;
}

void altura_libera(tAltura *altura)
{
    free(altura);
}

void altura_acessa(tAltura *altura, float *cm, float *m)
{
    *cm = altura->cm;
    *m = altura->m;
}

void altura_atribui(tAltura *altura, float cm, float m)
{
    altura->cm = cm;
    altura->m = m;
}

void altura_exibe(tAltura *altura)
{
    printf("%0.2fcm - %0.2fm\n", altura->cm, altura->m);
}

char * altura_get(tAltura *altura)
{
    char *alturaP;
    alturaP = (char *)malloc(sizeof(*altura) + 5);

    sprintf(alturaP, "%0.2fcm, %0.2fm", altura->cm, altura->m);

    return alturaP;
}

int altura_compara(tAltura *altura1, tAltura *altura2)
{
    if(altura1->cm < altura2->cm)
    {
        return -1;
    }
    else if(altura1->cm > altura2->cm) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

tAltura * altura_soma(tAltura *altura, float cm)
{
    altura->cm += cm;
    altura->m += cm / 100;
}

tAltura * altura_copia(tAltura *altura)
{
    tAltura *alturaNova; 
    alturaNova = altura_cria(altura->cm, altura->m);
    return alturaNova;
}