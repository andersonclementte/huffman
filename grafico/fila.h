#ifndef fila_h
#define fila_h
#include <stdio.h> 
#include <stdlib.h> 

typedef struct node { 
    int data; 
    struct node* next; 
  
} Node; 

Node* newNode(int d); 

int isEmpty_queue(Node** head);

void pop(Node** head);

void push(Node** head, int d, int *counter) ;


#endif