#ifndef hashtable_h
#define hashtable_h
#include "./header.h"

struct element {
  unsigned char bin[8];
  
};

struct hash {
  element *table[256]; 
};

hash* create_hash_table();

void put_bin_on_hash(hash *ht, unsigned char key, unsigned char b[], int j);

void print_hash(hash *ht);

#endif