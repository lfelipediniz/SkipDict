#include "../inc/dicionario.h"

int main() {
   SKIPLIST* dicionario = criar_sl();

   char operation[15];
   char palavra[MAX_PALAVRA];
   char definicao[MAX_DEFINICAO];

   while (1) {
      scanf("%s", operation);
      if (strcmp(operation, "insercao") == 0) {
         scanf("%s %s", palavra, definicao);
         inserir_sl(dicionario, palavra, definicao);
      } else if (strcmp(operation, "busca") == 0) {
         scanf("%s", palavra);
         NODE* resultado = buscar_sl(dicionario, palavra);
         printf("%s %s\n", palavra, resultado->definicao);
      } else if (strcmp(operation, "remocao") == 0) {
         deletar_sl(dicionario, palavra);
      } else if (strcmp(operation, "alteracao") == 0) {
         scanf("%s %s", palavra, definicao);
         update_sl(dicionario, palavra, definicao);
      } else if (strcmp(operation, "impressao") == 0) {
         char ch1;
         scanf("%c", &ch1);

         printarPalavrasInicial_sl(dicionario, ch1);
      }
   }

   return 0;
}