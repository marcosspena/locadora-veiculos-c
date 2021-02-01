/*
 * Permite ao cliente logado avaliar uma locadora a sua escolha, caso o nome digitado não seja encontrado na base de dados retorna erro.
 */

#include "libLocadoras.h"

int avaliarLocadora (char arqFisicoLocadoras[], char nomeLocadora[]){
   int opt = -1, posicao = 0;
   FILE *arqLocadora = fopen(arqFisicoLocadoras, "r+b");
   Locadora tmp;

   if (arqLocadora == NULL){
      printf("ERRO: Erro ao abrir arquivo de locadoras na funcao avaliarLocadora.\n");
      //Retorna 0 para não exibir nenhuma mensagem na função logAsNormalUser
      return 0;
   }

   while (fread(&tmp, sizeof(Locadora), 1, arqLocadora) !=0 ){
      //Caso não encontre a locadora, o valor de opt vai se manter -1, não precisando de verificador
      if (strcmp(nomeLocadora, tmp.nome) == 0)
      {
         printf("Qual a avaliação?(2-Ruim, 3-Bom, 4-Excelente)\n");
         scanf("%d", &opt);
         //Aumenta em 1 a avaliação conforme escolhida pelo cliente
         switch (opt)
         {
         case 2:
            tmp.avaliacao.ruim++;
            break;
         case 3:
            tmp.avaliacao.bom++;
            break;
         case 4:
            tmp.avaliacao.excelente++;
            break;
         default:
            break;
         }
      //Vai com o ponteiro para a posição do dado correto
      fseek(arqLocadora, posicao*sizeof(Locadora), SEEK_SET);
      //Substitui a informação cadastrada
      fwrite(&tmp, sizeof(Locadora), 1, arqLocadora);
      }
      //Encontra a posição do dado para usar a função fseek depois
      posicao++;
   }
   //Fecha o arquivo fisico
   fclose(arqLocadora);
   //Avaliacao do cliente para a locadora
   return opt;
}

