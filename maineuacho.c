#include "./header.h"

int main()
{
  char teste[22]="AAAAAABBBBBCCCCDDDEEF";
  char binary[8];
  heap*rip = create_heap();
  check_frequency(teste, rip);
  print_heap(rip->size, rip);
  /* printf("%s\n", teste);
  node *x=dequeue(rip);
  printf("%d %c\n", x->frequency, x->data);
  print_heap(rip->size, rip);
  x=dequeue(rip);
  printf("%d %c\n", x->frequency, x->data);
  print_heap(rip->size, rip);
  x=dequeue(rip);
  printf("%d %c\n", x->frequency, x->data);
  print_heap(rip->size, rip);
  x=dequeue(rip);
  printf("%d %c\n", x->frequency, x->data);
  print_heap(rip->size, rip);
  x=dequeue(rip);
  printf("%d %c\n", x->frequency, x->data);
  print_heap(rip->size, rip);
*/
  build_huff_tree(rip);
  hash *ht=create_hash_table();
  navigate(rip->items[1],binary,0,ht);
  print_preorder(rip->items[1]);
  printf("\n");

  print_hash(ht);
}

