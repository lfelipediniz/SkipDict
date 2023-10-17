#include "../inc/dicionario.h"

int main() {
   SKIPLIST* dicionario = criar_sl();

   char operation[15];
   char palavra[MAX_PALAVRA];
   char definicao[MAX_DEFINICAO];

   while (1) {
      scanf("%s", operation);
      if (strcmp(operation, "insercao") == 0) {
         scanf("%s", palavra);
         fgets(definicao, MAX_DEFINICAO, stdin);  // le com os espacos
         definicao[strcspn(definicao, "\n")] =
             '\0';  // tira a quebra de linha
         inserir_sl(dicionario, palavra, definicao);
      }

      else if (strcmp(operation, "busca") == 0) {
         scanf("%s", palavra);
         NODE* resultado = buscar_sl(dicionario, palavra);
         if (resultado) {
            printf("%s %s\n", palavra, resultado->definicao);
         } else {
            printf("Palavra não encontrada.\n");
         }
      }
      else if (strcmp(operation, "remocao") == 0) {
         deletar_sl(dicionario, palavra);
      }
      else if (strcmp(operation, "alteracao") == 0) {
         scanf("%s", palavra);
         fgets(definicao, MAX_DEFINICAO, stdin); 
         definicao[strcspn(definicao, "\n")] =
             '\0';  
         update_sl(dicionario, palavra, definicao);
      }
      else if (strcmp(operation, "impressao") == 0) {
         char ch1;
         while ((ch1 = getchar()) != '\n') {
            if (ch1 != ' ' && ch1 != '\t') {
               printarPalavrasInicial_sl(dicionario, ch1);
               break;
            }
         }
      }
   }

   return 0;
}