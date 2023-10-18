#include "skiplist.h"

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

bool skiplist_inserir(SKIPLIST *lista, ITEM *item)
{

    NO *ultimo_checado_camada[CAMADAS];
    memset(ultimo_checado_camada, 0, CAMADAS * sizeof(NO *));

    NO *no = no_criar(item);

    int camada = CAMADAS - 1;
    NO *iter = lista->camadas_primeiro[camada];
    NO *iter_ultimo_visitado = NULL;

    while (1)
    {
        if (iter == NULL)
        {
            camada -= 1;

            if ((camada >= 0))
            {

                iter_ultimo_visitado = NULL;
                iter = lista->camadas_primeiro[camada];
                continue;
            }
            else
            {
                printf("o no entrou na lista1\n");
                //  Caso onde não tem nehum nó na lista
                lista->camadas_primeiro[0] = no;
                lista->camadas_ultimo[0] = no;
                break;
            }
        }

        // printf("%d\n", iter->chave == no->chave);
        // printf("%s %s\n", item_get_str1(iter->chave), item_get_str1(no->chave));
        int cond = strcmp(item_get_str1(iter->chave), item_get_str1(no->chave));

        if (cond <= 0)
        {
            if (cond == 0)
            {
                // printf("falso?\n");
                return false;
            }
            else
            {
                camada -= 1;
                if ((camada < 0))
                {
                    printf("adicionou\n");
                    NO *aux = iter->proximo;
                    iter->proximo = no;
                    no->proximo = aux;
                    no->anterior = iter;
                    break;
                }
                else
                {
                    ultimo_checado_camada[camada + 1] = iter_ultimo_visitado;
                    iter = iter_ultimo_visitado->conjugado;
                }
            }
        }

        iter_ultimo_visitado = iter;
        iter = iter->proximo;
    }

    for (int i = 1; i < CAMADAS; i++)
    {
        if (randf() < PROB)
        {
            // printf("o no entrou na lista\n");
            NO *no_aux = no_criar(item);
            no_aux->conjugado = no;

            if (lista->camadas_primeiro[i] != NULL)
            {
                no_aux->proximo = ultimo_checado_camada[i]->proximo;
                ultimo_checado_camada[i]->proximo = no_aux;
                no_aux->anterior = ultimo_checado_camada[i];
            }
            else
            {
                lista->camadas_primeiro[0] = no;
                lista->camadas_ultimo[0] = no;
            }

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
    NO *iter_ultimo_visitado = NULL;

    while (1)
    {
        if (iter == NULL)
        {
            // printf("%d\n", camada);
            camada -= 1;
            if ((camada >= 0))
            {
                iter_ultimo_visitado = NULL;
                iter = lista->camadas_primeiro[camada];
                continue;
            }
            else
            {
                return NULL;
            }
        }

        // printf("%s %s\n", item_get_str1(iter->chave), chave);
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
                if (iter_ultimo_visitado != NULL)
                    iter = iter_ultimo_visitado->conjugado;
                else if (camada >= 0)
                {
                    iter_ultimo_visitado = iter;
                    iter = lista->camadas_primeiro[camada];
                }
                else
                {
                    return NULL;
                }
                continue;
            }
        }

        iter_ultimo_visitado = iter;
        iter = iter->proximo;
    }
}

ITEM *skiplist_remover(SKIPLIST *lista, char *chave)
{
    NO *base = _no_buscar(lista, chave);

    // printf("oi\n");

    if (base == NULL)
        return NULL;

    ITEM *ret = base->chave;

    while (base != NULL)
    {
        if (base->anterior == NULL)
        {
            lista->camadas_primeiro[base->camada] = base->proximo;
            if (base->proximo != NULL)
                base->proximo->anterior = NULL;
        }
        if (base->proximo == NULL)
        {
            lista->camadas_ultimo[base->camada] = base->anterior;
            if (base->anterior != NULL)
                base->anterior->proximo = NULL;
        }
        if (base->proximo != NULL && base->anterior != NULL)
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

// Essa bagulho aqui tá horrivel, redículo, mas funciona
ITEM **skiplist_busca_caractere(SKIPLIST *lista, char c)
{

    int camada = CAMADAS - 1;
    ITEM **ret;
    // Isso aqui muito provavelmente viola o conceito de TAD
    ret = (ITEM **)item_criar(NULL, NULL);
    NO *iter = lista->camadas_primeiro[camada];
    NO *iter_ultimo_visitado = NULL;
    // printf("oi\n");

    while (1)
    {
        if (iter == NULL)
        {
            camada -= 1;
            // printf("%d\n", camada);
            if ((camada >= 0))
            {
                iter_ultimo_visitado = NULL;
                iter = lista->camadas_primeiro[camada];
                continue;
            }
            else
            {
                return NULL;
            }
        }

        int cond = (c - item_get_str1(iter->chave)[0]);

        if (cond >= 0)
        {
            if (cond == 0)
            {
                // printf("oi\n");
                // Essa parte aqui tbm tá muito ruim
                while (iter->anterior != NULL)
                {
                    if (item_get_str1(iter->anterior->chave)[0] - c == 0)
                    {
                        iter = iter->anterior;
                        break;
                    }
                }

                {
                    int i = 0;
                    while (item_get_str1(iter->chave)[0] - c == 0)
                    {
                        // printf("%s\n", item_get_str1(iter->chave));
                        ret = realloc(ret, i + 1);
                        ret[i] = iter->chave;
                        i += 1;

                        if (iter->proximo == NULL)
                            break;
                        iter = iter->proximo;
                    }

                    ret = realloc(ret, i + 1);
                    ret[i] = NULL;

                    return ret;
                }
            }
            else
            {
                camada -= 1;
                iter = iter_ultimo_visitado->conjugado;
            }
        }

        iter_ultimo_visitado = iter;
        iter = iter->proximo;
    }
}

// talvez em letra maiuscula
// cetepe_eventos
// eesc@1953