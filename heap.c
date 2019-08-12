#include "./header.h"
#include "./heap.h"


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
        //printf("underflow\n");
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