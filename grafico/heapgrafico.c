#include "fila.h"
#include "heap.h"

 
heap * create_heap()
{
    heap *new= malloc(sizeof(heap));
    new->size=0;
    return new;
}

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

}

int isempty_heap(heap *rip)
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

int heap_item(heap * rip, int i)
{
    return rip->items[i];
}

void max_heapfy(heap *rip, int i, int *counter)
{
    int greatest;
    int leftindex = left_child(i);
    int rightindex = right_child(i);
    if (leftindex <= rip->size && rip->items[leftindex] > rip->items[i]) 
    {
        greatest = leftindex;
    } 
    else 
    {
        greatest = i;
    }
    if (rightindex <= rip->size && rip->items[rightindex] > rip->items[greatest]) 
    {
        greatest = rightindex;
    }
    if (rip->items[i] != rip->items[greatest]) 
    {
        swap(&rip->items[i], &rip->items[greatest]);
        (*counter)++;
        max_heapfy(rip, greatest, counter);
    }
}

void build_max_heap(heap* rip, int *counter)
{  
    int i;
    for ( i = rip->size/2; i >= 1; i--)
    {
        max_heapfy(rip, i, counter);
    }  
}

 void print_heap(int n, heap * rip)
{
    int i;
    int num;
    printf("Heap current state: ");
    
    if(!isempty_heap(rip))
    {
        for ( i = 1; i <= n-1; i++)
        {
            
            num=rip->items[i];
            printf("%d | ", num);
        }
        
        num=rip->items[i];
        printf("%d", num);
        printf("\n");
        printf("Smallest element: %d\n", rip->items[1]);
    }
        
    else
    {
        printf("empty\n");
        return;
    }
    
}

void enqueue(heap *rip, int item, int *counter)
{
    if(rip->size>=MAXSIZE)
    {
        printf("overflow\n");
    }
    else
    {
        rip->items[++rip->size]=item;
        int index=rip->size;
        int daddy_index=daddy(rip->size);
        build_max_heap(rip, counter);
    }
}