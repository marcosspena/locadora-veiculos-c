/*
 * Função responsável por gravar as informação do novo cliente (nome, endereço, contatos etc.) no arquivo arqFisicoCliente
 */


//Adicionada para que a função gravarCliente tenha acesso às definições de registros e funções
#include "libLocadoras.h"

void gravarCliente(char arqFisicoClientes[], Cliente c){
   FILE *pArqCliente = fopen (arqFisicoClientes, "ab");
   if (pArqCliente == NULL){
      printf("\nErro ao abrir arquivo de cliente em gravarCliente.\n"); 
      return;
   }
   fwrite(&c, sizeof(Cliente), 1, pArqCliente);
   fclose(pArqCliente);
   return;
}
