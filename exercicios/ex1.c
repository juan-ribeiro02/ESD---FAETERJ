#include<stdlib.h>
#include<stdio.h>

#define LIN 6
#define COL 6

int* preencherMatriz(int linha, int coluna);
void exibirMatriz(int *m, int linha, int coluna);
int somaDistancia(int vetor[], int tamanho, int *matriz, int linha, int coluna);
void perguntaCidades(int vetor[], int tamanho);

int main()
{
    int *mat;
    int i, j, resultado, tamanho = 6;
    int vetor[tamanho];
    
    perguntaCidades(vetor, tamanho);

    mat = preencherMatriz(LIN, COL);

    exibirMatriz(mat, LIN, COL); 

    resultado = somaDistancia(vetor, tamanho, mat, LIN, COL);

    printf("Distancia percorrida: %dKM", resultado);

    free(mat);
    return 0;
}

int somaDistancia(int vetor[], int tamanho, int *matriz, int linha, int coluna)
{
    int i, j, cidade1, cidade2, distancia, distTotal = 0;

    for(i = 1; i < tamanho; i++)
    {
        cidade1 = vetor[i-1] - 1;
        cidade2 = vetor[i] - 1;

        distancia = matriz[(cidade1 * coluna) +  cidade2];

        distTotal+=distancia;
    }

    return distTotal;
}

void perguntaCidades(int vetor[], int tamanho)
{
    int i;

    for(i = 0; i < tamanho; i++)
    {
        printf("\n%d cidade: ", i+1);
        scanf("%d", &vetor[i]);
    }
}

int* preencherMatriz(int linha, int coluna)
{
    int i, j;
    int *m;
    int dados[6][6] = {
        {0,   63, 210, 190, 300, 190},
        {63,  0,  160, 150, 95,  70},
        {210, 160, 0,  10,  120, 60},
        {190, 150, 10, 0,   110, 30},
        {300, 95,  120, 110, 0,   80},
        {190, 70,  60,  30,  80,  0}
    };
    
    m = malloc(linha * coluna * sizeof(int));
    
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            m[(i * coluna) + j] = dados[i][j];
        }
    }

    return m;
}

void exibirMatriz(int *m, int linha, int coluna)
{
    int i, j;

    for(i = 0; i < LIN; i++)
    {
        for(j = 0; j < COL; j++)
        {
            printf("%d ", m[(i * COL) + j]);
        }
        printf("\n");
    }
}