#include "../inc/dicionario.h"

struct dicionario_ {
   SKIPLIST *skiplist;
};

DICIONARIO *dicionario_criar() {
   DICIONARIO *dicionario = (DICIONARIO *)malloc(sizeof(DICIONARIO));
   if (dicionario != NULL) {
      dicionario->skiplist = skiplist_criar();
      return dicionario;
   }
   return NULL;
}

bool dicionario_apagar(DICIONARIO **dicionario) {
   if (*dicionario != NULL) {
      skiplist_apagar(&((*dicionario)->skiplist));
      free(*dicionario);
      *dicionario = NULL;
      return true;
   }
   return false;
}

bool dicionario_insercao(DICIONARIO *dicionario, char *str1, char *str2) {
   ITEM *item = item_criar(str1, str2);
   if (item != NULL) {
      if (skiplist_busca(dicionario->skiplist, str1) == NULL) {
         return skiplist_inserir(dicionario->skiplist, item);
      }
      item_apagar(&item);  // A palavra já existe, liberar memória do item
   }
   return false;
}

bool dicionario_alteracao(DICIONARIO *dicionario, char *str1, char *str2) {
   ITEM *item = skiplist_busca(dicionario->skiplist, str1);
   if (item != NULL) {
      item_set_str2(item, str2);
      return true;
   }
   return false;
}

bool dicionario_remocao(DICIONARIO *dicionario, char *str) {
   ITEM *item = skiplist_remover(dicionario->skiplist, str);
   if (item != NULL) {
      item_apagar(&item);
      return true;
   }
   return false;
}

ITEM *dicionario_busca(DICIONARIO *dicionario, char *str) {
   return skiplist_busca(dicionario->skiplist, str);
}

bool dicionario_impressao(DICIONARIO *dicionario, char *str) {
   bool encontrado = false;
   for (int i = 0; i < TAM_MAX; i++) {
      ITEM *item = skiplist_busca(dicionario->skiplist, str);
      if (item != NULL) {
         encontrado = true;
         item_imprimir(item);
      }
   }
   if (!encontrado) {
      printf("NAO HA PALAVRAS INICIADAS POR %s\n", str);
   }
   return encontrado;
}
