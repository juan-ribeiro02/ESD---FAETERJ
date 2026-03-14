#include<stdlib.h>
#include<stdio.h>

struct opiniao {
    char nome[30];
    int idade;
    int nota[4];
};
typedef struct opiniao tOp;

void preenche(tOp *pEnt);
void exibir(tOp pEnt[], int quantidade);

int main()
{
    tOp *ent;
    int i;

    ent = (tOp*)malloc(3 * sizeof(tOp));

    for (i = 0; i < 3; i++){
        preenche(&ent[i]);
    }
    
    exibir(ent, 3);

    free(ent);
}

void preenche(tOp *pEnt)
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
        printf("%s\n%d", pEnt[i].nome, pEnt[i].idade);

        for(j = 0; j < 4; j++)
        {
            printf("\nnota %d: %d", j, pEnt[i].nota[j]);
        }
        printf("\n");
    }
}