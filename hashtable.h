#ifndef hashtable_h
#define hashtable_h
#include "./header.h"

struct element {
  unsigned char bin[8];
  
};

struct hash {
  element *table[256]; 
};

/* 
This function creates a hash that will be used to allocate the new binary representantion for each caracter
the hash is created with the size of 256 each stance represents a caracter from the ASCII table and points to NULL

This fuctin returns a hash table
 */
hash* create_hash_table();

/*
Implements the binary representation embraced by the concept of the huffman tree in the hash table
for each stance that represents a read caracter is created a node that is connected by a pointer containing the binary representation
*/
void put_bin_on_hash(hash *ht, unsigned char key, unsigned char b[], int j);

void print_hash(hash *ht);

#endif