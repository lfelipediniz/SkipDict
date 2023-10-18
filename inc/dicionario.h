#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "skiplist.h"

typedef struct dicionario_ DICIONARIO;

DICIONARIO *dicionario_criar();
bool dicionario_apagar(DICIONARIO **dicionario);
bool dicionario_insercao(DICIONARIO *dicionario, char *str1, char *str2);
bool dicionario_alteracao(DICIONARIO *dicionario, char *str1, char *str2);
bool dicionario_remocao(DICIONARIO *dicionario, char *str);
ITEM *dicionario_busca(DICIONARIO *dicionario, char *str);
bool dicionario_impressao(DICIONARIO *dicionario, char c);

#endif
