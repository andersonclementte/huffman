#ifndef huff_h
#define huff_h
#include "./header.h"
#include "./tree.h"
#include "./heap.h"

void check_frequency(char *str, heap *rip);

node* merge(node *a, node *b);

void build_huff_tree(heap *rip);

#endif

