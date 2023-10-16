#include <stdio.h>
#include "lista.h"
#include "item.h"
#include "dicionario.h"
#include "skiplist.h"

int main()
{

    SKIPLIST *skip = skiplist_criar();

    ITEM *item = item_criar("aseefse", "rsjgnsrgns");
    skiplist_inserir(skip, item);

    

    return 0;
}