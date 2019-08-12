#include "./header.h"
#include "./huff.h"
#include "./tree.h"
#include "./heap.h"

int main()
{
  char teste[22]="AAAAAABBBBBCCCCDDDEEF";
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

  print_preorder(rip->items[1]);
  printf("\n");
}

