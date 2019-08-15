#ifndef heap_h
#define heap_h
#include "./header.h"

struct heap
{
    int size;
    node* items[MAXSIZE];
};

/* 
This function creates a heap that will be used to create the huffman tree
It allocates memory and returns the new heap
*/
heap * create_heap();

/*
This function swaps the address of two given nodes  
*/
void swap(node **a, node **b);

/*
This function checks if the heap is empty
It returns 0 if the heap is not empty otherwise returns 1
*/
int isempty(heap *rip);

/*
This function calculates the parents index of a node in the heap  
And returns its value
*/
int daddy(int i);

/*
This function calculates the left child index of a node in the heap
And returns its value 
*/
int left_child(int i);

/*
This function calculates the right child index of a node in the heap 
And returns its value
*/
int right_child(int i);

/*
Given an index this function returns the equivalent node in the heap
*/
node* heap_item(heap * rip, int i);

/*
This function maintains the heap properties
It compares each nodes seeing if their frequency is bigger or smaller and puts the smallests in front
*/
void min_heapfy(heap *rip, int i);

/*
This function creates a minimum heap
*/
void build_min_heap(heap* rip);

void print_heap(int n, heap * rip);
/*
This enqueues a node in the heap then calls the build_min_heap to maintein its properties
if the heap is already full it prints an error message
*/
void enqueue(heap *rip, node *n);

/*
This function removes the first node of the heap and calls the build_min_heap to maintein its properties
if the heap is empty it return NULL otherwise it returns the denqueued node
*/
node* dequeue(heap * rip);

#endif