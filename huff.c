#include "./header.h"
#include "./huff.h"

void check_frequency(FILE *archive, heap *rip)
{
  
  long long int frequency = 0, i, lenght;
  int array_freq[256];
  unsigned char aux;
  for(i=0;i<256;i++) 
  {
    array_freq[i]=0;
  }
  while (fscanf(archive, "%c", &aux)!=EOF)
  {
    
        array_freq[aux]++;
  }
  for(i=0;i<256;i++)
  {
    if(array_freq[i]!=0)
    {
      aux=i;
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

int tree_size(node* tree)
{
  if(tree==NULL)
  {
    return 0;
  }
  if(tree->data == '*' && is_leaf(tree)|| tree->data == '\\' && is_leaf(tree))
  {
    return 2;
  }
    
  return 1+tree_size(tree->left)+tree_size(tree->right);
  
}