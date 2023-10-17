#include "../inc/dicionario.h"

typedef struct skiplist_ {
   int level;
   NODE *header;
} SKIPLIST;

SKIPLIST *criar_sl() {
   SKIPLIST *lista = (SKIPLIST *)malloc(sizeof(SKIPLIST));

   NODE *header = (NODE *)malloc(sizeof(NODE));
   if (!lista || !header) return NULL;

   lista->header = header;
   strncpy(header->palavra, "", MAX_PALAVRA);
   header->prox = (NODE **)malloc(sizeof(NODE *) * (SKIPLIST_MAX_LEVEL + 1));

   int i;

   for (i = 0; i <= SKIPLIST_MAX_LEVEL; i++) {
      header->prox[i] = NULL;
   }

   lista->level = 1;

   return lista;
}

static int randLevel() {
   int level = 1;
   while (rand() < RAND_MAX / 2 && level < SKIPLIST_MAX_LEVEL) level++;
   return level;
}

NODE *buscar_sl(SKIPLIST *lista, char *palavra) {
   int i;
   NODE *aux = lista->header;

   for (i = lista->level; i >= 1; i--) {
      while (aux->prox[i] && strcmp(aux->prox[i]->palavra, palavra) < 0) {
         aux = aux->prox[i];
      }
   }

   if (aux->prox[1] && strcmp(aux->prox[1]->palavra, palavra) == 0)
      return aux->prox[1];
   else
      return NULL;
}

int inserir_sl(SKIPLIST *lista, char *palavra, char *definicao) {
   NODE *update[SKIPLIST_MAX_LEVEL + 1];
   NODE *aux = lista->header;
   int i;

   for (i = lista->level; i >= 1; i--) {
      while (aux->prox[i] && strcmp(aux->prox[i]->palavra, palavra) < 0) {
         aux = aux->prox[i];
      }
      update[i] = aux;
   }

   aux = aux->prox[1];

   if (aux && strcmp(aux->palavra, palavra) == 0) {
      strncpy(aux->definicao, definicao, MAX_DEFINICAO);
      return 0;
   } else {
      int level = randLevel();

      if (level > lista->level) {
         for (i = lista->level + 1; i <= level; i++) {
            update[i] = lista->header;
         }
         lista->level = level;
      }

      aux = (NODE *)malloc(sizeof(NODE));
      strncpy(aux->palavra, palavra, MAX_PALAVRA);
      strncpy(aux->definicao, definicao, MAX_DEFINICAO);
      aux->prox = (NODE **)malloc(sizeof(NODE *) * (level + 1));

      for (i = 1; i <= level; i++) {
         aux->prox[i] = update[i]->prox[i];
         update[i]->prox[i] = aux;
      }
   }

   return 1;
}

int update_sl(SKIPLIST *lista, char *palavra, char *definicao) {
   NODE *aux = buscar_sl(lista, palavra);
   if (aux) {
      strncpy(aux->definicao, definicao, MAX_DEFINICAO);
      return 1;
   }
   return 0;
}

int deletar_sl(SKIPLIST *lista, char *palavra) {
   NODE *update[SKIPLIST_MAX_LEVEL + 1];
   NODE *aux = lista->header;
   int i;

   for (i = lista->level; i >= 1; i--) {
      while (aux->prox[i] && strcmp(aux->prox[i]->palavra, palavra) < 0) {
         aux = aux->prox[i];
      }
      update[i] = aux;
   }

   aux = aux->prox[1];

   if (aux && strcmp(aux->palavra, palavra) == 0) {
      for (i = 1; i <= lista->level; i++) {
         if (update[i]->prox[i] != aux) break;
         update[i]->prox[i] = aux->prox[i];
      }
      free(aux->prox);
      free(aux);

      while (lista->level > 1 && lista->header->prox[lista->level] == NULL) {
         lista->level--;
      }

      return 1;
   }
   return 0;
}

void liberar_sl(SKIPLIST *lista) {
   NODE *aux = lista->header->prox[1];
   while (aux) {
      printf("%s: %s\n", aux->palavra, aux->definicao);
      aux = aux->prox[1];
   }
}

int printarPalavrasInicial_sl(SKIPLIST *lista, char ch1) {
   int printouPalavra = 0; 
   NODE *aux = lista->header->prox[1];

   while (aux && aux->palavra[0] < ch1) {
      aux = aux->prox[1];
   }
   while (aux && aux->palavra[0] == ch1) {
      printf("%s: %s\n", aux->palavra, aux->definicao);
      aux = aux->prox[1];
      printouPalavra = 1; // pelo menos uma palavra foi impressa
   }

   return printouPalavra;
}
