#ifndef hashtable_h
#define hashtable_h
#include "./header.h"

struct element {
  char bin[8];
  
};

struct hash {
  element *table[256]; 
};

hash* create_hash_table();

void put(hash *ht, unsigned char key, char b[]);

void print_hash(hash *ht);

#endif