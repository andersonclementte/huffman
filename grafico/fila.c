
// C code to implement Priority Queue 
// using Linked List 

#include "fila.h"
#include "heap.h"

  
// Function to Create A New Node 
Node* newNode(int d) 
{ 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->data = d; 
    temp->next = NULL; 
  
    return temp; 
} 
  
// Function to check is list is empty 
int isEmpty_queue(Node** head) 
{ 
    return (*head) == NULL; 
} 

// Return the value at head 
int peek(Node** head) 
{ 
    return (*head)->data; 
} 
  
// Removes the element with the 
// highest priority form the list 
void pop(Node** head) 
{ 
    Node* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
} 
  
// Function to push according to priority 
void push(Node** head, int d, int *counter) 
{ 
    Node* start = (*head); 
  
    // Create new Node 
    Node* temp = newNode(d); 
  
    // Special Case: The head of list has lesser 
    // priority than new node. So insert new 
    // node before head node and change head node. 
    if ((*head)->data < d) { 
  
        // Insert New Node before head 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
  
        // Traverse the list and find a 
        // position to insert new node 
        while (start->next != NULL && start->next->data > d) { 
            start = start->next; 
            (*counter)++;
            //printf("-- %d --\n", *counter);
        }
  
        // Either at the ends of the list 
        // or at required position 
        temp->next = start->next; 
        start->next = temp; 
    } 
} 
// Driver code 
