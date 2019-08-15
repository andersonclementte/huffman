#include "./header.h"


hash* create_hash_table() {
	hash *hashtable = (hash*) malloc(sizeof(hash));
    int i;
    for(i=0;i<256;i++)
    {
        hashtable->table[i]=NULL;
    }
	return hashtable;
}

void put_bin_on_hash(hash *ht, unsigned char key, unsigned char b[],int size)
{
    int i;
    element *new=(element*)malloc(sizeof(element));
    for(i=0;i<size;i++)
    {
        new->bin[i]=b[i];
    }
    ht->table[key]=new;

}

void print_hash(hash *ht)
{
  int i;
  for(i=0;i<256;i++)
  {
      if(ht->table[i] != NULL)
      {
        printf("%c: %s", i, ht->table[i]->bin);
        printf("\n"); 
      }
  }
}