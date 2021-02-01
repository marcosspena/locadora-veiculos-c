/*
 * Função responsável por gravar as informação da nova locadora (nome, endereço, contatos etc.) no arquivo arqFisicoLocadoras
 */

#include "libLocadoras.h"
void gravarLocadora(char arqFisicoLocadoras[], Locadora locadora){
   FILE *pArqLocadoras = fopen (arqFisicoLocadoras, "ab");
   if (pArqLocadoras == NULL){
      printf("\nErro ao abrir arquivo de locadoras em gravarLocadora.\n"); 
      return;
   }
   fwrite(&locadora, sizeof(Locadora), 1, pArqLocadoras);
   fclose(pArqLocadoras);
   return;
}

