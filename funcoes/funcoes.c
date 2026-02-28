#include<stdlib.h>
#include<stdio.h>

int* preencherMatriz(int linha, int coluna); //preencher vetor com alocacao dinamica unica
void exibirMatriz(int *m, int linha, int coluna); //exibir vetor com alocacao dinamica unica

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