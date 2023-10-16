#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "lista.h"
#include "item.h"

typedef struct dicionario_ DICIONARIO;

DICIONARIO *dicionario_criar();
bool dicionario_apagar(DICIONARIO **dicionario);
bool dicionario_insercao(DICIONARIO *dicionario, char *str1, char *str2);
bool dicionario_alteracao(DICIONARIO *dicionario, char *str1, char *str2);
bool dicionario_remocao(DICIONARIO *dicionario, char *str);
ITEM *dicionario_busca(DICIONARIO *dicionario, char *str);
bool dicionario_impressao(DICIONARIO *dicionario, char *str);

#endif
