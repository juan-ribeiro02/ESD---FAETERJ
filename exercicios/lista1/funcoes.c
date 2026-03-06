#include"funcoes.h"
#include<stdlib.h>
#include<stdio.h>

int* preencherMatriz(int linha, int coluna)
{
    int i, j;
    int *m;

    m = malloc(linha * coluna * sizeof(int));

    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            m[(i * coluna) + j] = 0;
        }
    }

    return m;
}

void exibirMatriz(int *m, int linha, int coluna)
{
    int i, j;

    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            printf("%d ", m[(i * coluna) + j]);
        }
        printf("\n");
    }
}

int divisaoInteira(int dividendo, int divisor, int *quociente, int *resto)
{
    if (dividendo == 0 && divisor == 0)
    {
        return -1;
    } 
    else if (divisor == 0)
    {
        return 0;
    }

    *quociente = dividendo/divisor;
    *resto = dividendo % divisor;

    return 1;
}