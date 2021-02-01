/*
 * Função para listar todos os clientes cadastrados no arqFisicoClientes e suas respectivas informações
 */

#include "libLocadoras.h"

void listarClientes(char arqFisicoClientes[]){
  FILE *arqCliente = fopen(arqFisicoClientes, "rb");
  Cliente tmp;
  int i;
  //Verifica se o arquivo foi aberto corretamente
  if (arqCliente == NULL){
    printf("ERRO: Erro ao abrir arquivo arqFisicoClientes na funcao listarClientes");
    return;
  }
  printf("***Imprimindo lista de clientes***\n\n");
  //Para cada cliente, imprime as informações dele
  while (fread(&tmp, sizeof(Cliente), 1, arqCliente) !=0){
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
    if (tmp.numeroAvaliacoes != 0)
    {
      printf("\nAvaliacoes desse cliente");
      for (i = 0; i < tmp.numeroAvaliacoes; i++)
      {
        printf("\nLocadora: %s - Avaliacao: %d", tmp.vetAvaliacoes[i].nomeLocadora, tmp.vetAvaliacoes[i].avaliacaoLocadora);
      }
    }
    //Pula linhas antes do proximo cliente para facilitar a visualização
    printf("\n\n");
  }
  //Fecha o arquivo fisico
  fclose(arqCliente);
  return;
}


