#ifndef heap_h
#define heap_h
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
 
#define MAXSIZE 100000
 
 typedef struct heap heap;

 
struct heap
{
    int size;
    int items[MAXSIZE];
};


heap * create_heap();

int isempty_heap(heap *rip);
int daddy(int i);
int left_child(int i);
int heap_item(heap * rip, int i);
int right_child(int i);
void max_heapfy(heap *rip, int i, int *counter);
void swap(int *a, int *b);
void build_max_heap(heap* rip, int *counter);
void print_heap(int n, heap * rip);
void enqueue(heap *rip, int item, int *counter);

#endif