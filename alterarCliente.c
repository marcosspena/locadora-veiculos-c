/*
 * Função que permite ao root alterar endereço e/ou contatos do cliente selecionado
 * Caso não encontre ou o arquivo não abra, retorna erro
 */

#include "libLocadoras.h"

int alterarCliente(char arqFisicoClientes[], char usernameCliente[]){
   FILE *arqCliente = fopen(arqFisicoClientes, "r+b");
   Cliente tmp, tmpdois;
   int verificadorCliente = 0, posicao = 0, posicaodois, opt;

   //Verifica se o arquivo foi aberto corretamente
   if (arqCliente == NULL){
      return 1;
   }
   //Verifica se esse username já foi cadastrado
   while (fread(&tmp, sizeof(Cliente), 1, arqCliente) !=0 ){
      if (strcmp(usernameCliente, tmp.login.username) == 0)
      { 
         //Caso encontre o usuário na base de dados o verificador fica 1
         verificadorCliente = 1;
         //Pergunta o que deseja alterar no cadastro
         //Impede que seja digitado valor diferente de 1, 2 e 0
         do
         {
            printf("Qual dado deseja alterar:\n");
            printf("1 - Endereço\n");
            printf("2 - Contato\n");
            printf("0 - Cancelar\n");
            scanf("%d", &opt);
         }while (opt !=1 && opt !=2 && opt !=0);
         switch (opt)
         {
         case 1:
            printf("\nRua:");
            scanf("\n%[^\n]s", tmp.endereco.rua);
            printf("\nNumero:");
            scanf("%d", &tmp.endereco.numero);
            printf("\nComplemento:");
            scanf("\n%[^\n]s", tmp.endereco.complemento);
            printf("\nCidade:");
            scanf("\n%[^\n]s", tmp.endereco.cidade);
            printf("\nCEP:");
            scanf("%d", &tmp.endereco.cep);
            break;
         case 2:
            printf("\nFone:");
            scanf("\n%[^\n]s", tmp.contato.fone);
            printf("\nE-mail:");
            scanf("\n%[^\n]s", tmp.contato.email);
            break;
         case 0:
            fclose(arqCliente);
            return 2;
            break;
         default:
            break;
         }
      //Vai com o ponteiro para a posição do dado correto
      fseek(arqCliente, posicao*sizeof(Cliente), SEEK_SET);
      //Substitui a informação cadastrada
      fwrite(&tmp, sizeof(Cliente), 1, arqCliente);
      //"Desfaz" o fseek e faz o ponteiro avançar
      fseek(arqCliente, (posicao+1)*sizeof(Cliente), SEEK_SET);
      }  
      //Encontra a posição do dado para usar a função fseek depois
      posicao++;      
   }
   //Caso não tenha encontrado esse username, retorna erro para a logAsRoot imprimir a mensagem
   if (verificadorCliente == 0)
   {
      return -1;
   }
    
   //Fecha o arquivo fisico
   fclose(arqCliente);
   return 0;
}
