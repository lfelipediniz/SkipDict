#include "skiplist.h"

float randf() { return ((float)(rand()) / (float)(RAND_MAX)); }


// Deus há de me perdoar por esse crime que eu vou cometer

typedef struct no_ NO;

struct no_
{
    ITEM *chave;
    NO *proximo;
    NO *conjugado;
};

struct lista_
{
    NO *primeiro;
    NO *ultimo;
    int tamanho;
};

struct skiplist_
{
    LISTA *camadas[CAMADAS];
};

SKIPLIST *skiplist_criar(void)
{
    SKIPLIST *skiplist;
    skiplist = malloc(sizeof(SKIPLIST));

    for (int i = 0; i < CAMADAS; i++)
    {
        skiplist->camadas[i] = lista_criar();
    }

    return skiplist;
}

bool skiplist_inserir(SKIPLIST *lista, ITEM *item)
{
    lista_inserir(lista->camadas[0], item);

    for (int i = 1; i < CAMADAS; i++)
    {
        if (randf() < PROB)
        {
            lista_inserir(lista->camadas[i], item);
        }
        else
        {
            break;
        }
    }
}

ITEM *skiplist_remover(SKIPLIST *lista, char *chave);

bool skiplist_apagar(SKIPLIST **lista)
{
    for (int i = 0; i < CAMADAS; i++)
    {
        lista_apagar(&((*lista)->camadas[i]));
    }

    free(*lista);
}

ITEM *skiplist_busca(SKIPLIST *lista, char *chave)
{
    int camada = CAMADAS - 1;
    NO* iter = lista->camadas[camada]->primeiro;
    
    while (iter != NULL)
    {
        if (item_compare(iter->chave, chave) < 0);
    }

    return iter;
    
}