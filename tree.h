#ifndef tree_h
#define tree_h
#include "./header.h"
#include "./huff.h"
#include "./heap.h"

struct node
{
    void * data;
    int frequency;
    node* left;
    node* right;

};

node* create_node(void * item, int freq, node* l, node* r);

void print_preorder(node * tree);

void navigate(node *root, unsigned char binary[], int i, hash *ht);

int is_leaf(node *tree);

#endif