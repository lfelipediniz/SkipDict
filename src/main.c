#include "dicionario.h"

int main()
{
   DICIONARIO *dicionario = dicionario_criar();

   char operation[15];
   char palavra[140];
   char definicao[280];
   int flag;

   while (scanf("%s", operation) != EOF)
   {
      // int i = 0;
      // while (i < 10200)
      // {
      //    i++;
      //    scanf("%s", operation);
      // Continua até o final da entrada
      if (strcmp(operation, "insercao") == 0)
      {
         scanf("%s", palavra);
         fgets(definicao, 280, stdin);
         definicao[strcspn(definicao, "\n")] = '\0';

         if (!dicionario_insercao(dicionario, palavra, definicao))
         {
            printf("OPERACAO INVALIDA\n");
         }
      }
      else if (strcmp(operation, "busca") == 0)
      {
         scanf("%s", palavra);

         ITEM *resultado = dicionario_busca(dicionario, palavra);

         if (resultado != NULL)
         {
            printf("%s%s\n", item_get_str1(resultado), item_get_str2(resultado));
         }
         else
         {
            printf("OPERACAO INVALIDA\n");
         }
      }
      else if (strcmp(operation, "remocao") == 0)
      {
         scanf("%s", palavra);
         if (!dicionario_remocao(dicionario, palavra))
            printf("OPERACAO INVALIDA\n");
      }
      else if (strcmp(operation, "alteracao") == 0)
      {
         // Ta meio errado ainda
         scanf("%s", palavra);
         fgets(definicao, 280, stdin);
         definicao[strcspn(definicao, "\n")] = '\0';

         if (!dicionario_alteracao(dicionario, palavra, definicao))
            printf("OPERACAO INVALIDA\n");
      }
      else if (strcmp(operation, "impressao") == 0)
      {
         char ch1;
         getchar();
         ch1 = getchar();

         flag = dicionario_impressao(dicionario, ch1);
         if (!flag)
            printf("NAO HA PALAVRAS INICIADAS POR %c\n", ch1);
      }
      else
      {
         printf("OPERACAO INVALIDA\n");
      }
   }

   dicionario_apagar(&dicionario);

   return 0;
}
