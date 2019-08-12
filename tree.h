#ifndef tree_h
#define tree_h
#include "./header.h"
#include "./huff.h"
#include "./heap.h"

struct node
{
    char data;
    int frequency;
    node* left;
    node* right;

};

node* create_node(char item, int freq, node* l, node* r);

void print_preorder(node * tree);

#endif