#include "./header.h"

int main()
{
  unsigned char arquivo[100];
  int option;
  printf("\nBem vindo ao zip-zop, um programa em c desenvolvido por estudantes\nde engenharia de computação da UFAL para a disciplica de estrutura de dados\n\n\n");
  
  while (1) {
    printf("\nEscolha uma das opções:\n(1) - Comprimir\n(2) - Descomprimir\n(3) - Sair\n");
    scanf("%d", &option);
    if (option == 1) {
      printf("\nDigite o nome do arquivo que deseja compactar:\n");
      scanf(" %[^\n]s", arquivo);
      compress(arquivo);
    } else if (option == 2) {
      printf("Not implemented yet\n");
    } else if (option == 3) {
      printf("\nprograma desenvolvido por:\nAnderson Clemente\nLarissa Duarte\nPedro Melo\nPedro Tenorio\nAgradecemos a preferencia ;)\n");
      return 0;
    } else {
      continue;
    }
  }
  
  return 0;

}

