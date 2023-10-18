#ifndef SKIPLIST_H
#define SKIPLIST_H

#define inicial 0
#define ERRO -32000
#define TAM_MAX 1000

#define CAMADAS 4
#define PROB 0.2

#include <stdlib.h>
#include <string.h>

#include "item.h"

float randf();

typedef struct skiplist_ SKIPLIST;

SKIPLIST *skiplist_criar(void);
bool skiplist_inserir(SKIPLIST *lista, ITEM *item);
ITEM *skiplist_remover(SKIPLIST *lista, char *chave);
bool skiplist_apagar(SKIPLIST **lista);
ITEM *skiplist_busca(SKIPLIST *lista, char *chave);
ITEM **skiplist_busca_caractere(SKIPLIST *lista, char c);

#endif