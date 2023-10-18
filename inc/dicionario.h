#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PALAVRA 100
#define MAX_DEFINICAO 240
#define SKIPLIST_MAX_LEVEL 10

typedef struct node_ {
   char palavra[MAX_PALAVRA];
   char definicao[MAX_DEFINICAO];
   struct node_ **prox;
} NODE;

typedef struct skiplist_ SKIPLIST;

SKIPLIST *criar_sl();
NODE *buscar_sl(SKIPLIST *lista, char *palavra);
int inserir_sl(SKIPLIST *lista, char *palavra, char *definicao);
int update_sl(SKIPLIST *lista, char *palavra, char *definicao);
int deletar_sl(SKIPLIST *lista, char *palavra);
void liberar_sl(SKIPLIST *lista);
int printarPalavrasInicial_sl(SKIPLIST *lista, char ch1);

#endif
