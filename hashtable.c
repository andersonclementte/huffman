#include "./header.h"


hash* create_hash_table() {
	hash *hashtable = (hash*) malloc(sizeof(hash));
    int i;
    for(i=0;i<256;i++)
    {
        hashtable->table[i]->bin[0]='*';
    }
	return hashtable;
}

void put_bin_on_hash(hash *ht, unsigned char key, char b[])
{
    int i;
    for(i=0;i<strlen(b);i++)
    {
        ht->table[key]->bin[i]=b[i];
    } 
}

void print_hash(hash *ht)
{
  hash* aux=ht;
  int i;
  for(i=0;i<256;i++)
  {
      if(ht->table[i]->bin[0] != '*')
      {
        printf("%c: %s", i, ht->table[i]->bin);
        printf("\n"); 
      }
  }
}