#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define USER 3

struct opiniao {
    char nome[30];
    int idade;
    int nota[4];
};
typedef struct opiniao tOp;

void preenche(tOp pEnt[]);
void exibir(tOp pEnt[], int quantidade);
void vetPonteiros(tOp pEnt[], tOp *vetNome[], tOp *vetIdade[],int quantidade);
void imprimirPonteiros(tOp *indice[], int quantidade);
void bubbleSortPorAno(tOp *indice[], int quantidade);
void bubbleSortPorNome(tOp *indice[], int quantidade);

int main()
{
    tOp ent[USER];
    tOp *vNome[USER];
    tOp *vIdade[USER];
    int i;
    int resposta;

    for (i = 0; i < USER; i++){
        preenche(&ent[i]);
    }
    vetPonteiros(ent, vNome, vIdade, USER);
    
    while(resposta != 4)
    {
        printf("\n+--------------------+---------------------+-----------------------------------+\n");
        printf("  | 1 - EXIBIR P/ NOME | 2 - EXIBIR P/ IDADE | 3 - EXIBIR P/ INCLUSAO | 4 - SAIR |");
        printf("\n+--------------------+---------------------+-----------------------------------+\n");
    
        printf(">>> ");
        scanf("%d", &resposta);
    
        if(resposta == 1)
        {
            bubbleSortPorNome(vNome, USER);
            imprimirPonteiros(vNome, USER);
        }

        if(resposta == 2)
        {
            bubbleSortPorAno(vIdade, USER);
            imprimirPonteiros(vIdade, USER);
        }

        if (resposta == 3)
        {
            exibir(ent, USER);
        }
    }

    return 0;
}

void bubbleSortPorNome(tOp *indice[], int quantidade)
{
    int i, j;
    tOp *temp;

    for(i = 0; i < quantidade - 1; i++)
    {
        for(j = 0; j < quantidade - i - 1; j++)
        {
            if(strcmp(indice[j]->nome, indice[j + 1]->nome) > 0)
            {
                temp = indice[j];
                indice[j] = indice[j + 1];
                indice[j + 1] = temp;
            }
        }
    }
}

void bubbleSortPorAno(tOp *indice[], int quantidade)
{
    int i, j;
    tOp *temp;

    for(i = 0; i < quantidade - 1; i++)
    {
        for(j = 0; j < quantidade - i - 1; j++)
        {
            if(indice[j]->idade > indice[j + 1]->idade)
            {
                temp = indice[j];
                indice[j] = indice[j + 1];
                indice[j + 1] = temp;
            }
        }
    }
}

void vetPonteiros(tOp pEnt[], tOp *vetNome[], tOp *vetIdade[],int quantidade)
{
    int i;

    for(i = 0; i < quantidade; i++)
    {
        vetNome[i] = &pEnt[i];
        vetIdade[i] = &pEnt[i];
    }
}

void imprimirPonteiros(tOp *indice[], int quantidade)
{
    int i, j;

    for(i = 0; i < quantidade; i++)
    {
        printf("Nome: %s -- Idade: %d", indice[i]->nome, indice[i]->idade);

        for(j = 0; j < 4; j++)
        {
            printf("\nnota %d: %d", j, indice[i]->nota[j]);
        }
        printf("\n");
    }
}

void preenche(tOp pEnt[])
{
    int i;

    printf("dados:");
    scanf("%s", pEnt->nome);
    scanf("%d", &pEnt->idade);
    
    for(i = 0; i < 4; i++)
    {
        scanf("%d", &pEnt->nota[i]);
    }
}   

void exibir(tOp pEnt[], int quantidade)
{
    int i, j;

    for(i = 0; i < quantidade; i++)
    {
        printf("Nome: %s -- Idade: %d", pEnt[i].nome, pEnt[i].idade);

        for(j = 0; j < 4; j++)
        {
            printf("\nnota %d: %d", j, pEnt[i].nota[j]);
        }
        printf("\n");
    }
}