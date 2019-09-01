#include "fila.h"
#include "heap.h"

int main() {
    int i;
    int i_q = 1, i_h = 1; 
    FILE* grafico_out = fopen("grafico_out.txt","w");
    fprintf(grafico_out,"cont fila heap\n");
    heap *rip=create_heap();
    rip->items[1]=0;
    Node *queue= newNode(0);

    printf("digite a quantidade de elementos para as estruturas: ");
    scanf("%d",&i);
    int ale_num,cont;
    for(cont = 1; cont <= i; cont++) {
        ale_num=rand();
        push(&queue, ale_num, &i_q);
        enqueue(rip, ale_num, &i_h);
        printf("queue: %d heap: %d\n", i_q, i_h);
        fprintf(grafico_out,"%d %d %d\n",cont, i_q, i_h);
        i_q=1;
        i_h=1;
    }

    fclose(grafico_out);
    printf("Concluido\n");

    //free_node(&queue);
    return 0;
}

//gcc heapgrafico.c heap.h fila.c fila.h main.c -o main