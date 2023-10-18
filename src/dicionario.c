#include "../inc/dicionario.h"

struct dicionario_
{
   SKIPLIST *skiplist;
};

DICIONARIO *dicionario_criar()
{
   DICIONARIO *dicionario = (DICIONARIO *)malloc(sizeof(DICIONARIO));
   if (dicionario != NULL)
   {
      dicionario->skiplist = skiplist_criar();
      return dicionario;
   }
   return NULL;
}

bool dicionario_apagar(DICIONARIO **dicionario)
{
   if (*dicionario != NULL)
   {
      skiplist_apagar(&((*dicionario)->skiplist));
      free(*dicionario);
      *dicionario = NULL;
      return true;
   }
   return false;
}

bool dicionario_insercao(DICIONARIO *dicionario, char *str1, char *str2)
{
   ITEM *item = item_criar(str1, str2);
   if (item != NULL)
   {
      return skiplist_inserir(dicionario->skiplist, item);
   }
   return false;
}

bool dicionario_alteracao(DICIONARIO *dicionario, char *str1, char *str2)
{
   ITEM *item = skiplist_busca(dicionario->skiplist, str1);
   if (item != NULL)
   {
      item_set_str2(item, str2);
      return true;
   }
   return false;
}

bool dicionario_remocao(DICIONARIO *dicionario, char *str)
{
   ITEM *item = skiplist_remover(dicionario->skiplist, str);
   if (item != NULL)
   {
      item_apagar(&item);
      return true;
   }
   return false;
}

ITEM *dicionario_busca(DICIONARIO *dicionario, char *str)
{
   return skiplist_busca(dicionario->skiplist, str);
}

bool dicionario_impressao(DICIONARIO *dicionario, char c)
{
   ITEM **item = skiplist_busca_caractere(dicionario->skiplist, c);
   if (item == NULL)
      return false;

   int i = 0;
   while (item[i] != NULL)
   {
      printf("%s%s\n", item_get_str1(item[i]), item_get_str2(item[i]));
      i++;
   }

   return true;
}
