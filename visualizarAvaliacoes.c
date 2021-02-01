/*
 * Permite ao cliente visualizar todas as suas avaliações realizadas(de cada locadora)
 */

#include "libLocadoras.h"

void visualizarAvaliacoes(char arqFisicoClientes[], char usernameCliente[]){
  FILE *arqCliente = fopen(arqFisicoClientes, "rb");
  Cliente tmp;
  int i = 0;

  //Encontra o cliente no arquivo arqFisicoClientes
  while (fread(&tmp, sizeof(Cliente), 1, arqCliente) !=0){
    if (strcmp(usernameCliente, tmp.login.username) == 0){
      //Verifica se existem avaliacoes para esse cliente
      if (tmp.numeroAvaliacoes > 0)
      {
        printf("\nSuas avaliacoes");
        for (i = 0; i < tmp.numeroAvaliacoes; i++)
        {
          printf("\nLocadora: %s - Avaliacao: %d", tmp.vetAvaliacoes[i].nomeLocadora, tmp.vetAvaliacoes[i].avaliacaoLocadora);
        }
      }
      else
      {
        //Caso não tenha avaliações retorna a mensagem
        printf("Voce ainda nao realizou nenhuma avaliacao!\n");
        return;
      }
    }
  }
  fclose(arqCliente);
  printf("\n");
  return;
}
