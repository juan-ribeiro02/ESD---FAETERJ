#include "Lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Em seguida, um tipo para a lista */
struct tipo_lista
{
    int* vnos;
    int qtnos;
    int maximo;
    int ehclassificada; // 1: classificada 0: não classificada
    int temrepeticao;   // 1: com repetição 0: sem repetição
};

int retira_varios(tLista * pl, int no);
int busca_des_srep(tLista *pl,int chave,int *pos);//feito
int busca_bin(tLista *pl, int chave, int *pos);//feito
void encontra_posInicEqt(tLista*pl,int * posRet, int *qt, int valor);//feito
void chegaparacaMC(tLista *pl, int posRet, int qt);//feito
void chegaparalaMC(tLista *pl, int pos, int qt);//feito

/* cria lista vazia */
tLista * lista_cria_vazia(int maximo, int classif, int repet)
{
    tLista *pl = (tLista*) malloc(sizeof(tLista));
    pl->vnos = (int*) malloc(sizeof(int) * maximo);
    pl->qtnos = 0;
    pl->maximo = maximo;
    pl->ehclassificada = classif;
    pl->temrepeticao = repet;
    return pl;
}

// lista está vazia?
int lista_vazia(const tLista *pl)
{
    return (pl->qtnos == 0);
}

// lista está cheia?
int lista_cheia(const tLista *pl)
{
    return (pl->qtnos == pl->maximo);
}

// lista com repetição?
int lista_repet(const tLista *pl)
{
    return (pl->temrepeticao == 1);
}

// lista classificada?
int lista_classif(const tLista *pl)
{
    return (pl->ehclassificada == 1);
}

// percorre a lista
void lista_percorre(const tLista *pl)
{
    int i;
    printf("\npercorrendo:\n");
    for(i = 0; i < pl->qtnos; i++)
        printf("%d - ", pl->vnos[i]);
    printf("\nfim percorrendo\n");
}

int lista_inclui(tLista *pl, int novo)
{
    int posNovo, achou;

    if (lista_cheia(pl))
        return 0;  // não pode incluir pq tá cheio

    if (!lista_classif(pl)) {
        if (!lista_repet(pl) && busca_des_srep(pl, novo, &posNovo))
            return -1; // não pode incluir pq já existe
        posNovo = pl->qtnos;
    }
    else {
        achou = busca_bin(pl, novo, &posNovo);
        if (achou && !lista_repet(pl))
            return -1; // não pode incluir pq já existe
        chegaparalaMC(pl, posNovo, 1);
    }

    pl->vnos[posNovo] = novo;
    pl->qtnos++;
    return 1; // inclusão correta
}

int lista_exclui(tLista *pl, int no)
{
    int posRet, achou, qt = 1;

    if (lista_vazia(pl))
        return 0;

    if (lista_repet(pl) && !lista_classif(pl))
        return retira_varios(pl, no);

    if (lista_classif(pl))
        achou = busca_bin(pl, no, &posRet);
    else
        achou = busca_des_srep(pl, no, &posRet);

    if (!achou)
        return -1; // exclusão de inexistente

    if (lista_repet(pl)) {
        printf("\nantes %d %d", posRet, qt);
        encontra_posInicEqt(pl, &posRet, &qt, no);
        printf("\ndepois %d %d", posRet, qt);
    }

    chegaparacaMC(pl, posRet, qt);
    printf("\n\n%d %d ", qt, pl->qtnos);
    pl->qtnos -= qt;
    printf("\n%d %d ", qt, pl->qtnos);
    return 1;
}

// FUNÇÕES AUXILIARES

//faz uma busca binaria retornando se achou(1) ou nao achou(0),
//e passa a posicao de onde o numero procurado deve ser colocado por meio de um ponteiro(*pos)
int busca_bin(tLista *pl, int chave, int *pos){
    int inicio = 0, meio, achou = 0;
    int fim = pl->qtnos - 1;
    
    while(inicio <= fim)
    {
        meio = (inicio + fim)/2;
        
        if(pl->vnos[meio] == chave)
        {
            achou = 1;
            break;
        }
        else
        {
            if(chave < pl->vnos[meio])
            {
                fim = meio - 1;
            }
            else
            {
                inicio = meio + 1;
            }
        }
    }
    
    if(achou == 1)
    {
        (*pos) = meio;
    }
    else
    {
        (*pos) = inicio;
    }
    
    return achou;
}

//faz a busca em uma lista sem classificacao e sem repeticao 
//so percorre a lista comparando a chave com todos os itens da lista
//retorna 1 se achar e 0 se nao e passa a posicao por ponteiro
int busca_des_srep(tLista *pl,int chave,int *pos)
{
    int i;
    
    for(i = 0; i < pl->qtnos; i++)
    {
        if(pl->vnos[i] == chave)
        {
            (*pos) = i;
            return 1;
        }
    }
    
    return 0;
}

//funcao 
void encontra_posInicEqt(tLista*pl,int * posRet, int *qt, int valor)
{
    int i = *posRet, cont = 0;
    
    while((i>0) && (pl->vnos[i - 1] == valor))
    {
        i--;
    }
    
    *posRet = i;
    
    while((i < pl->qtnos) && (pl->vnos[i] == valor))
    {
        cont++;
        i++;
    }
    
    *qt = cont;
}

//é...
void chegaparacaMC(tLista *pl, int posRet, int qt)
{
	int num_ele=pl->qtnos - (posRet+qt);

	if(num_ele>0)
	{
		memcpy(&pl->vnos[posRet],&pl->vnos[posRet+qt],num_ele*sizeof(int));
	}
}

//opa...
void chegaparalaMC(tLista *pl, int pos, int qt) {
	int num_ele=pl->qtnos - pos;

	if(num_ele>0)
	{
		memcpy(&pl->vnos[pos+qt],&pl->vnos[pos],num_ele*sizeof(int));
	}
}

int retira_varios(tLista * pl, int no)
{
    int i = 0, achou = 0;
    
    while(i < pl->qtnos)
    {
        if(pl->vnos[i] == no)
        {
            chegaparacaMC(pl, i, 1);
            pl->qtnos--;
            achou = 1;
        }
        else
        {
            i++;
        }
    }
    
    if (achou)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// CHEGA PARA CÁ  ==> TRANSFORMAR PARA memcpy
void chegaparaca(tLista *pl, int pos, int qt)
{
    int i;
    for(i = pos; i <= pl->qtnos - qt; i++)
        pl->vnos[i] = pl->vnos[i + qt];
}

// CHEGA PARA LÁ ==> TRANSFORMAR PARA memcpy
void chegaparala(tLista *pl, int pos)
{
    int i;
    for(i = pl->qtnos; i > pos; i--)
        pl->vnos[i] = pl->vnos[i - 1];
}
