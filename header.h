#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "./huff.h"
#include "./tree.h"
#include "./heap.h"
#include "./hashtable.h"

typedef struct node node;
typedef struct heap heap;
typedef struct element element;
typedef struct hash hash;



#define MAXSIZE 100000