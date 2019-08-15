#include "./header.h"
#include "./tree.h"




node* create_node(void * item, int freq, node* l, node* r)
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
    printf("( f:%d c:%c ",tree->frequency, tree->data);
    print_preorder(tree->left);
    print_preorder(tree->right);
    printf(") ");
  }
  else
  printf("()");
    
 }

 int is_leaf(node *tree)
 {
    if(tree->left == NULL && tree->right == NULL)
      return 1;
    else
      return 0;
 }

 void navigate(node *root, unsigned char binary[], int i, hash *ht)
 {
   if(root->left)
   {
     binary[i]='0';
     navigate(root->left,binary,i+1, ht);
   }
   if(root->right)
   {
     binary[i]='1';
     navigate(root->right,binary,i+1, ht);
   }

   if(is_leaf(root))
   {
     put_bin_on_hash(ht, root->data,binary,i);
   }
 }

