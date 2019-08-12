#ifndef heap_h
#define heap_h
#include "./header.h"
#include "./huff.h"
#include "./tree.h"


struct heap
{
    int size;
    node* items[MAXSIZE];
};

//
heap * create_heap();
//
void swap(node **a, node **b);

int isempty(heap *rip);

int daddy(int i);

int left_child(int i);

int right_child(int i);

node* heap_item(heap * rip, int i);

void min_heapfy(heap *rip, int i);

void build_min_heap(heap* rip);

void print_heap(int n, heap * rip);

void enqueue(heap *rip, node *n);

node* dequeue(heap * rip);

#endif