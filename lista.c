#include "lista.h"

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

NO *no_criar(ITEM *chave, NO *proximo)
{
    NO *no;
    no = (NO *)malloc(sizeof(NO));
    no->chave = chave;
    no->proximo = proximo;

    return no;
}

void no_apagar(NO **no)
{
    free(*no);
}

LISTA *lista_criar(void)
{
    LISTA *lista;
    lista = (LISTA *)malloc(sizeof(lista));

    NO *primeiro;
    NO *ultimo;

    primeiro = no_criar(NULL, NULL);
    ultimo = no_criar(NULL, NULL);

    if (lista != NULL)
    {
        lista->primeiro = primeiro;
        lista->ultimo = ultimo;
        lista->tamanho = 0;
    }

    return lista;
}

bool lista_inserir(LISTA *lista, ITEM *item)
{
    if (lista != NULL && item != NULL)
    {

        NO *no = no_criar(item, NULL);
        if (lista->tamanho == 0)
        {
            lista->primeiro = no;
            lista->ultimo = no;
            lista->tamanho += 1;
        }
        else
        {

            NO *iter = (lista)->primeiro;
            NO *anterior = NULL;

            while (iter != NULL)
            {
                if (strcmp(item_get_str1(no->chave), item_get_str1(iter->chave)) > 0)
                {
                    anterior = iter;
                    iter = iter->proximo;
                }
                else
                {
                    if (anterior == NULL)
                    {
                        lista->primeiro = no;
                    }
                    else
                    {
                        anterior->proximo = no;
                    }

                    no->proximo = iter;
                    lista->ultimo = no;
                    lista->tamanho += 1;
                    return true;
                }
            }

            anterior->proximo = no;
            no->proximo = iter;
            lista->ultimo = no;
            lista->tamanho += 1;
        }

        return true;
    }
    else
    {
        return false;
    }
}

ITEM *lista_remover(LISTA *lista, char *chave)
{
    NO *iter = lista->primeiro;
    NO *anterior = NULL;

    while (iter != NULL)
    {
        if (strcmp(item_get_str1(iter->chave), chave) == 0)
        {
            if (anterior != NULL)
            {
                if (lista->tamanho == 1)
                {
                    lista->primeiro = NULL;
                    lista->ultimo = NULL;
                    lista->tamanho = 0;
                }
                else
                {
                    lista->primeiro = lista->primeiro->proximo;
                    lista->tamanho -= 1;
                }
            }
            else
            {
                anterior->proximo = iter->proximo;
            }

            ITEM *ret = iter->chave;
            no_apagar(&iter);
            return ret;
        }

        anterior = iter;
        iter = iter->proximo;
    }
}

bool lista_apagar(LISTA **lista)
{
    NO *iter = (*lista)->primeiro;

    while (iter != NULL)
    {
        NO *prox = iter->proximo;
        item_apagar(&(iter->chave));
        no_apagar(&iter);
        iter = prox;
    }

    free(*lista);
    return true;
}

ITEM *lista_busca(LISTA *lista, char *chave)
{
    NO *iter = (lista)->primeiro;

    while (iter != NULL)
    {
        if (strcmp(item_get_str1(iter->chave), chave) == 0)
        {
            printf("oi\n");
            return iter->chave;
        }
        printf("oi2\n");
    }

    return NULL;
}
