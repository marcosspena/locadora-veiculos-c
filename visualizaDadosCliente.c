/*
 * Permite ao cliente que está logado ver suas próprias informações
 */

#include "libLocadoras.h"
void visualizaDadosCliente(char arqFisicoClientes[], LogInfo userLog){
  FILE *arqCliente = fopen(arqFisicoClientes, "rb");
  Cliente tmp;
  int i;

  //Verifica se o arquivo foi aberto corretamente
  if (arqCliente == NULL){
    printf("ERRO: Erro ao abrir arquivo arqFisicoClientes na funcao visualizaDadosCliente");
    return;
  }
  //Para cada cliente, imprime as informações dele
  while (fread(&tmp, sizeof(Cliente), 1, arqCliente) !=0){
    if (strcmp(userLog.username, tmp.login.username) == 0){
      printf("\nUsername: %s", tmp.login.username);
      printf("\nNome: %s", tmp.nome);
      printf("\nSobrenome: %s", tmp.sobrenome);
      //Endereço
      printf("\nRua: %s", tmp.endereco.rua);
      printf("\nNumero: %d", tmp.endereco.numero);
      printf("\nComplemento: %s", tmp.endereco.complemento);
      printf("\nCidade: %s", tmp.endereco.cidade);
      printf("\nCEP: %d", tmp.endereco.cep);
      //Contato
      printf("\nFone: %s", tmp.contato.fone);
      printf("\nE-mail: %s", tmp.contato.email);
      //Data nascimento
      printf("\nData de nascimento: %d/%d/%d", tmp.dataNascimento.dia, tmp.dataNascimento.mes, tmp.dataNascimento.ano);
      //Total de avaliações
      printf("\nTotal de avaliacoes: %d", tmp.numeroAvaliacoes);
      //Imprime as avaliações uma a uma, caso existam avaliações para esse cliente
      printf("\nAvaliacoes desse cliente");
      if (tmp.numeroAvaliacoes > 0)
      {
        for (i = 0; i < tmp.numeroAvaliacoes; i++)
        {
            printf("\nLocadora: %s - Avaliacao: %d", tmp.vetAvaliacoes[i].nomeLocadora, tmp.vetAvaliacoes[i].avaliacaoLocadora);
        }
      }
    }
  }
  //Fecha o arquivo fisico
  fclose(arqCliente);
  return;
}

