#include <stdio.h>
#include "../inc/item.h"
#include "../inc/dicionario.h"
#include "../inc/skiplist.h"

int main()
{

    printf("oi");

    SKIPLIST *skip = skiplist_criar();

    ITEM *item = item_criar("aseefse", "rsjgnsrgns");
    skiplist_inserir(skip, item);
    ITEM *item2 = skiplist_busca(skip, "aseefse");

    printf("%s", item_get_str2(item2));

    return 0;
}