#include "./header.h"
#include "./huff.h"


void check_frequency(char *str, heap *rip)
{
  int frequency = 0, i, lenght;
  char aux;
  lenght=strlen(str);
  for ( i = 0; i < lenght; i++)
  {
    if(str[i]!='*')
    {
      aux=str[i];
      break;
    }
    
  }
  //se der erro, vamos usar o \n
 
  if(i==lenght)
    {
      return;
    }
  for ( i = 0; i < lenght; i++)
  {
    if(str[i]==aux)
    {
      frequency++;
      str[i]='*';
    }
  }
  node *new=create_node(aux,frequency,NULL,NULL);
  enqueue(rip, new);

  check_frequency(str, rip);

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