#include "../inc/skiplist.h"

float randf() { return ((float)(rand()) / (float)(RAND_MAX)); }

// Deus há de me perdoar por esse crime que eu vou cometer

typedef struct no_ NO;

struct no_
{
    ITEM *chave;
    NO *proximo;
    NO *anterior;
    NO *conjugado;
    int camada;
};

NO *no_criar(ITEM *chave)
{
    NO *no;
    no = (NO *)malloc(sizeof(NO));
    no->chave = chave;
    no->proximo = NULL;
    no->anterior = NULL;
    no->conjugado = NULL;
    no->camada = 0;

    return no;
}

void no_apagar(NO **no)
{
    free(*no);
    *no = NULL;
}

struct skiplist_
{
    NO *camadas_primeiro[CAMADAS];
    NO *camadas_ultimo[CAMADAS];
};

SKIPLIST *skiplist_criar(void)
{

    SKIPLIST *skiplist;
    skiplist = malloc(sizeof(SKIPLIST));

    return skiplist;
}

bool _insercao_camadas(SKIPLIST *lista, int camada, NO *no)
{
    if (lista->camadas_primeiro[camada] == NULL)
    {
        lista->camadas_primeiro[camada] = no;
        lista->camadas_ultimo[camada] = no;
        return true;
    }
    else
    {
        lista->camadas_ultimo[camada]->proximo = no;
        no->anterior = lista->camadas_ultimo[camada];
        lista->camadas_ultimo[camada] = no;

        return true;
    }
    return false;
}

bool skiplist_inserir(SKIPLIST *lista, ITEM *item)
{
    NO *no = no_criar(item);

    _insercao_camadas(lista, 0, no);

    for (int i = 1; i < CAMADAS; i++)
    {
        if (randf() < PROB)
        {
            NO *no_aux = no_criar(item);
            no_aux->conjugado = no;
            _insercao_camadas(lista, i, no_aux);
            no = no_aux;
        }
        else
        {
            break;
        }
    }

    return true;
}

NO *_no_buscar(SKIPLIST *lista, char *chave)
{
    int camada = CAMADAS - 1;
    NO *iter = lista->camadas_primeiro[camada];
    NO *iter_anterior = NULL;

    while (1)
    {
        if (iter == NULL)
        {
            camada -= 1;

            if ((camada >= 0))
            {
                iter_anterior = NULL;
                iter = lista->camadas_primeiro[camada];
                continue;
            }
            else
            {
                return NULL;
            }
        }

        int cond = strcmp(item_get_str1(iter->chave), chave);

        if (cond >= 0)
        {
            if (cond == 0)
            {
                return iter;
            }
            else
            {
                camada -= 1;
                iter = iter_anterior->conjugado;
            }
        }

        iter_anterior = iter;
        iter = iter->proximo;
    }
}

ITEM *skiplist_remover(SKIPLIST *lista, char *chave)
{
    NO *base = _no_buscar(lista, chave);
    ITEM *ret = base->chave;

    while (base != NULL)
    {
        if (base->anterior == NULL)
        {
            lista->camadas_primeiro[base->camada] = base->proximo;
        }
        if (base->proximo == NULL)
        {
            lista->camadas_ultimo[base->camada] = base->anterior;
        }
        if (base->proximo == NULL && base->anterior != NULL)
        {
            base->anterior->proximo = base->proximo;
            base->proximo->anterior = base->anterior;
        }

        NO *aux = base->conjugado;

        no_apagar(&base);
        base = aux;
    }

    return ret;
}

bool skiplist_apagar(SKIPLIST **lista)
{
    for (int i = 0; i < CAMADAS; i++)
    {
        NO *iter = (*lista)->camadas_primeiro[i];

        while (iter != NULL)
        {
            NO *aux = iter->proximo;
            no_apagar(&iter);
            iter = aux;
        }
    }

    free(*lista);
    *lista = NULL;

    return true;
}

ITEM *skiplist_busca(SKIPLIST *lista, char *chave)
{
    NO *no = _no_buscar(lista, chave);
    if (no != NULL)
        return no->chave;
    else
        return NULL;
}

// talvez em letra maiuscula
// cetepe_eventos
// eesc@1953