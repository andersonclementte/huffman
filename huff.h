#ifndef huff_h
#define huff_h
#include "./header.h"

/*
This function creates a 256 size array, each stance representing a caracter in the ASCII scale
And stores the frequency of each one occurrence 
After that it creates a node pointing to null containing the caracter and its frequency and enqueues the node in the heap
*/
void check_frequency(unsigned char *str, heap *rip);

/*
This function receives two nodes and creates a new node that points to the given nodes
Its caracter is '*' and freaquency is the sum of their frequencies
It returns the created node
*/
node* merge(node *a, node *b);

/*
This function dequeues two nodes of the heap and calls merge sending the two dequeued nodes and then enqueues the new node 
It proceeds until the heap size is bigger than one 
*/
void build_huff_tree(heap *rip);

#endif

