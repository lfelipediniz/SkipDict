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

NO *no_criar(ITEM *chave)
{
    NO *no;
    no = (NO *)malloc(sizeof(NO));
    no->chave = chave;
    no->proximo = NULL;
    no->conjugado = NULL;

    return no;
}

void no_apagar(NO **no)
{
    free(*no);
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

ITEM *skiplist_remover(SKIPLIST *lista, char *chave);

bool skiplist_apagar(SKIPLIST **lista)
{
    // for (int i = 0; i < CAMADAS; i++)
    // {
    //     lista_apagar(&((*lista)->camadas[i]));
    // }

    // free(*lista);
    return true;
}

ITEM *skiplist_busca(SKIPLIST *lista, char *chave)
{
    int camada = CAMADAS - 1;
    NO *iter = lista->camadas_primeiro[camada];
    NO *iter_anterior = NULL;

    while (1)
    {
        if (iter == NULL)
        {
            iter_anterior = iter;
            iter = iter->proximo;
            if (iter == NULL)
            {
                camada -= 1;

                if ((camada + 1))
                {
                    iter_anterior = NULL;
                    iter = lista->camadas_primeiro[camada];
                }
                else
                    break;
            }
        }

        int cond = strcmp(item_get_str1(iter->chave), chave);

        if (cond >= 0)
        {
            if (cond == 0)
            {
                return iter->chave;
            }
            else
            {
                camada -= 1;
                iter = iter_anterior->conjugado;
            }
        }
    }

    return NULL;
}

// talvez em letra maiuscula
// cetepe_eventos
// eesc@1953