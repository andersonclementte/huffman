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

/*
This function creates a node with the item and frequency given,poiting its left and right to the given nodes  
*/
node* create_node(void * item, int freq, node* l, node* r);

/*
This function prints the tree in pre order
*/
void print_preorder(node * tree);

/*
This function navegate thought the tree until it finds a leaf
While it runs if it goes left we add 0 to an array of caracters otherwise we add 1
When a leaf in found we put the array in the hash position of the leaf caracter   
*/
void navigate(node *root, unsigned char binary[], int i, hash *ht);

/*
This function checks if the node is a leaf and returns 1 if true otherwise returns 0
*/
int is_leaf(node *tree);

#endif