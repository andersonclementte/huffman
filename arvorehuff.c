#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXSIZE 100000

typedef struct node node;
typedef struct heap heap;

struct heap
{
    int size;
    node* items[MAXSIZE];
};

struct node
{
    char data;
    int frequency;
    node* left;
    node* right;

};



node* create_node(char item, int freq, node* l, node* r)
{
  node* new=(node*) malloc(sizeof(node));
  new->data=item;
  new->frequency=freq;
  new->left=l;
  new->right=r;

  return new;
}

heap * create_heap()
{
    heap *new= malloc(sizeof(heap));
    new->size=0;
   return new;
}


void swap(node **a, node **b)
{
    node* temp;
    temp=*a;
    *a=*b;
    *b=temp;

}

int isempty(heap *rip)
{
    if(rip->size<=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}





int daddy(int i)
{
    return i/2;
}

int left_child(int i)
{
    return i * 2;
}

int right_child(int i)
{
    return (i*2)+1;
}

node* heap_item(heap * rip, int i)
{
    return rip->items[i];
}

void min_heapfy(heap *rip, int i)
{
    int smallest;
    int leftindex = left_child(i);
    int rightindex = right_child(i);
    if (leftindex <= rip->size && rip->items[leftindex]->frequency < rip->items[i]->frequency) 
    {
        smallest = leftindex;
    } 
    else 
    {
        smallest = i;
    }
    if (rightindex <= rip->size && rip->items[rightindex]->frequency < rip->items[smallest]->frequency) 
    {
        smallest = rightindex;
    }
    if (rip->items[i]->frequency != rip->items[smallest]->frequency) 
    {
        swap(&rip->items[i], &rip->items[smallest]);
        min_heapfy(rip, smallest);
    }
}

void build_min_heap(heap* rip)
{  
    int i;
    for ( i = rip->size/2; i >= 1; i--)
    {
        min_heapfy(rip, i);
    }
   
}
 
 void print_heap(int n, heap * rip)
{
    int i;
    int num;
    char letra;
    printf("Heap current state: \n");
    
    if(!isempty(rip))
    {
        for ( i = 1; i <= n-1; i++)
        {
            
            num=rip->items[i]->frequency;
            letra=rip->items[i]->data;
            printf("frequencia :%d  letra:%c\n", num, letra);
        }
        
        num=rip->items[i]->frequency;
        letra=rip->items[i]->data;
        printf("frequencia :%d  letra:%c\n", num, letra);
        printf("\n");
       
    }
        
    else
    {
        printf("empty\n");
        return;
    }
    
}

void enqueue(heap *rip, node *n)
{
    if(rip->size>=MAXSIZE)
    {
        printf("overflow\n");
    }
    else
    {
        rip->items[++rip->size]=n;
        build_min_heap(rip);
    
    }
    
}

node* dequeue(heap * rip)
{
    if(isempty(rip))
    {
        printf("underflow\n");
        return NULL;
    }
    else
    {
        node* item=rip->items[1];
        rip->items[1]=rip->items[rip->size];
        rip->size--;

        min_heapfy(rip, 1);

        return item;

    }
    
}

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

 void print_preorder(node * tree) {
   
  if (tree) 
  {
      
    printf(" ( f:%d c:%c",tree->frequency, tree->data);
    print_preorder(tree->left);
    print_preorder(tree->right);
    printf(") ");
  }
    else
    {
        printf(" () ");
    }
    
 }

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