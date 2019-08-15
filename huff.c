#include "./header.h"
#include "./huff.h"


void check_frequency(char *str, heap *rip)
{
  int frequency = 0, i, lenght;
  int array_freq[256];
  for(i=0;i<256;i++)
  {
    array_freq[i]=0;
  }
  char aux;
  lenght=strlen(str);
  for ( i = 0; i < lenght-1; i++)
  {
    array_freq[str[i]]++;
  }
  for(i=0;i<256;i++)
  {
    if(array_freq[i]!=0)
    {
      aux=i;
      if(aux == '*')
      {
        aux='*\\';
      }
      node *new=create_node(aux,array_freq[i],NULL,NULL);
      enqueue(rip, new);
    }
  }

}

node* merge(node *a, node *b)
{
  int sum=(a->frequency)+(b->frequency);
  node *new=create_node('*',sum,a,b);
  return new;
}

void build_huff_tree(heap *rip)
{
  if(!isempty(rip))
  {
    while(rip->size > 1)
    {
      node *a=dequeue(rip);
      node *b=dequeue(rip);
      node *merged=merge(a,b);
      enqueue(rip,merged);
    }
  }
  else
  {
    printf("empty heap\n");
  }
  
}