#include <stdio.h>
#include "item.h"
#include "dicionario.h"
#include "skiplist.h"

int main()
{
    SKIPLIST *skip = skiplist_criar();

    ITEM *item = item_criar("aseefse", "rsjgnsrgns");
    skiplist_inserir(skip, item);

    ITEM *item2 = skiplist_busca(skip, "aseefse");

    printf("%s\n", item_get_str2(item2));

    if (skiplist_busca(skip, "aseefse") == NULL)
    {
        printf("Apagou\n");
    }

    skiplist_apagar(&skip);

    return 0;
}