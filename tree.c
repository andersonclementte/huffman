#include "./header.h"
#include "./tree.h"




node* create_node(char item, int freq, node* l, node* r)
{
  node* new=(node*) malloc(sizeof(node));
  new->data=item;
  new->frequency=freq;
  new->left=l;
  new->right=r;

  return new;
}

void print_preorder(node * tree) 
{
   
  if (tree) 
  {
      
    printf("f:%d c:%c ",tree->frequency, tree->data);
    print_preorder(tree->left);
    print_preorder(tree->right);
  }
    
    
 }