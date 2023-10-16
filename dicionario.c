#include "dicionario.h"

// O dicionario consiste em um array de listas onde cada indice desse
// array corresponde a uma letra do alfabeto, onde 'a' corresponde ao
// indice 0 e 'z' corresponde ao indice 26
struct dicionario_
{
    LISTA *paginas[26];
};

DICIONARIO *dicionario_criar()
{
    DICIONARIO *dicionario;
    dicionario = malloc(sizeof(DICIONARIO));

    for (int i = 0; i < 26; i++)
    {
        dicionario->paginas[i] = lista_criar();
    }

    return dicionario;
}

bool dicionario_apagar(DICIONARIO **dicionario)
{
    free(*dicionario);
}

bool dicionario_insercao(DICIONARIO *dicionario, char *str1, char *str2)
{
    int indice = tolower(str1[0]) - 'a';
    ITEM *item = item_criar(str1, str2);
    lista_inserir(dicionario->paginas[indice], item);
}

bool dicionario_alteracao(DICIONARIO *dicionario, char *str1, char *str2);
bool dicionario_remocao(DICIONARIO *dicionario, char *str);

ITEM *dicionario_busca(DICIONARIO *dicionario, char *str)
{
    int indice = tolower(str[0]) - 'a';

    return lista_busca(dicionario->paginas[indice], str);
}

bool dicionario_impressao(DICIONARIO *dicionario, char *str);