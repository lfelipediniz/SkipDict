#ifndef LISTA_H
    #define LISTA_H

    #define inicial 0
    #define ERRO -32000
    #define ORDENADA 0
    #define TAM_MAX 1000
    
    #include "item.h"
    #include <string.h>
                       
    typedef struct lista_ LISTA;

    LISTA *lista_criar(void);
    bool lista_inserir(LISTA *lista, ITEM *item);
    ITEM *lista_remover(LISTA *lista, char* chave);
    bool lista_apagar(LISTA **lista);
    ITEM *lista_busca(LISTA *lista, char* chave);

#endif