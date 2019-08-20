#include "./header.h"

int main()
{
  unsigned char arquivo[100];
  int option;
  printf("Welcome to Zip Zop:\n");
  
  while (1) {
    printf("Choose your destiny:\n(1) - Compress\n(2) - Descompress\n(3) - Exit\n");
    scanf("%d", &option);
    if (option == 1) {
      printf("Digite o nome do arquivo que deseja compactar:\n");
      scanf(" %[^\n]s", arquivo);
      printf("%s\n", arquivo);
      compress(arquivo);
    } else if (option == 2) {
      printf("Not implemented yet\n");
    } else if (option == 3) {
      return 0;
    } else {
      continue;
    }
  }
  switch(option){
    case 1: 
            break;
    case 2:
            break;
    default: 
            printf("invalido\n");
            break;
  }


  return 0;

}

