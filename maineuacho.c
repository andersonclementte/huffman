#include "./header.h"

int main()
{
  unsigned char * teste, arquivo[100];
  teste=malloc(sizeof(unsigned char)*1000);
  int option;
  printf("Welcome to Zip Zop:\n");
  printf("Choose your destiny:\n (1) - Compress\n(2) - Descompress\n");
  scanf("%d", &option);
  
  switch(option){
    case 1: 
            printf("Digite o nome do arquivo que deseja compactar:\n");
            scanf(" %[^\n]s", arquivo);
            compress(arquivo);
            break;
    case 2:
            break;
    default: printf("invalido\n");
  }

}

