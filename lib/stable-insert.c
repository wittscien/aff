#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "treap.h"
#include "stable-i.h"

const struct AffSymbol_s *
aff_stable_insert(struct AffSTable_s *st, const char *name)
{
    struct Block_s *b;
    struct AffSymbol_s *sym;
    int len;

    if (st == 0 || name == 0)
	return 0;

    len = strlen(name) + 1;
    sym = aff_treap_lookup(st->treap, name, len);
    if (sym)
	return sym;

    if (st->last_block->used == BLOCK_SIZE) {
	b = malloc(sizeof (struct Block_s));
	if (b == 0)
	    return 0;
	aff_stable_iblock(b, st->size);
	st->last_block->next = b;
	st->last_block = b;
    }
    b = st->last_block;
    sym = &b->symbol[b->used];
    sym->name = malloc(strlen(name) + 1);
    if (sym->name == 0)
	return 0;
    strcpy((char *)sym->name, name);
    sym->id = st->size;
    if (aff_treap_insert(st->treap, sym->name, len, sym) != 0) {
	free((void *)sym->name);
	return 0;
    }
    b->used++;
    st->size++;
    st->file_size += len;
    return sym;
}
