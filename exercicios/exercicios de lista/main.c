#include <stdio.h>
#include "Lista.h"

int main()
{
    tLista * lista;
    lista=lista_cria_vazia(5, 0, 1); //  classif , com repet
    //lista_inclui(lista,2);
    lista_inclui(lista, 5);
    //lista_inclui(lista,2);
    lista_inclui(lista, 9);
    lista_inclui(lista, 3);
    lista_inclui(lista, 10);
    lista_inclui(lista, 10);

    
    lista_percorre(lista);
    
    
    lista_exclui(lista, 10);
    
    lista_percorre(lista);
    
    return 0;
}