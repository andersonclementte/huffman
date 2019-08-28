#include "heapgrafico.c"
#include "fila.c"

int main() {
    int i;
    FILE* arquivo_temp = fopen("testando.txt","w");
    heap *rip=create_heap();
    rip->items[1]=0;
    Node *queue= newNode(0);

    printf("digite a quantidade de elementos para as estruturas: ");
    scanf("%d",&i);
    int ale_num,cont;
    for(cont = 1; cont <= i; cont++) {
        ale_num = rand() % i + 1; 
        push(&queue, ale_num);
        enqueue(rip, ale_num);
    }

    fclose(arquivo_temp);
    printf("Concluido\n");

    //free_node(&queue);
    return 0;
}