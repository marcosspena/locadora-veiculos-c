/*
 * Função para remover um cliente baseado no username.
 * A remoção é realizada no arquivo arqFisicoClientes e no arquivo arqFisicoLogin.
 *
 * https://www.codingunit.com/c-tutorial-deleting-a-record-from-a-binary-file
 */

#include "libLocadoras.h"
int removerCliente(char arqFisicoClientes[], char arqFisicoLogin[], char username[]){
    //Abre o arquivo arqFisicoClientes para modo de leitura e escrita (r+) no iníco do arquivo e o associa a variável arq, que é utilizada
    //para a manipulação das informações presentes no arquivo arqFisicoClientes	   
   FILE *arq = fopen (arqFisicoClientes, "r+b");
   if (arq == NULL){
       printf("\nErro ao abrir arquivo de clientes em remover cliente.\n"); 
       return 1;
   }

   //Abre/cria o arquivo tmp.bin para modo de escrita (w) e o associa a variável arqTmp, que é utilizada como backup, ou seja, para copiar as   informações que não devem ser removidas (ou seja, aquela cujo username é diferente do username a ser removido) arqFisicoClientes. 
   FILE *arqTmp = fopen ("tmp.bin", "wb");
   if (arqTmp == NULL){
       printf("\nErro ao abrir arquivo de tmpCliente em remover cliente.\n"); 
       return 1;
   }

   //Abre o arquivo arqFisicoLogin para modo de leitura e escrita (r+) e o associa a variável arq2, que é utilizada para a manipulação das
   //informações presentes no arquivo arqFisicoLogin
   FILE *arq2 = fopen (arqFisicoLogin, "r+b");
   if (arq2 == NULL){
       printf("\nErro ao abrir arquivo de login em remover cliente.\n"); 
       return 1;
   }

   //Abre/cria o arquivo tmp2.bin para modo de escrita (w) e o associa a variável arqTmp2, que é utilizada como backup, ou seja, para copiar
   //as informações que não devem ser removidas (ou seja, aquela cujo username é diferente do username a ser removido) arqFisicoLogin. 
   FILE *arqTmp2 = fopen ("tmp2.bin", "wb");
   if (arqTmp2 == NULL){
       printf("\nErro ao abrir arquivo de tmpLogin em remover cliente 2.\n"); 
       return 1;
   }

   Cliente c;
   LogInfo l;
   int encontrou = 0;
   //Verifica a existência do username no arquivo arqFisicoLogin
   while (fread(&c, sizeof(Cliente), 1, arq) != 0 && fread(&l, sizeof(LogInfo), 1, arq2) != 0){
       //Caso o username lido do arquivo seja o username a ser removicod, ele não é escrito nos arquivos backup arqTmp e arqTmp2 pois ele deve ser removido da base	   
       if (strcmp(c.login.username, username) == 0){
          encontrou  = 1;
       }
       //O username no lido do arquivo não é o username a ser removido, então ele precisa ser mantido no arquivo e escrito para os arquivos backup arqTmp e arqTmp2 
       else{
           fwrite(&c, sizeof(Cliente), 1, arqTmp);
           fwrite(&l, sizeof(LogInfo), 1, arqTmp2);
       }
   }

   fclose(arq);
   fclose(arqTmp);
   fclose(arqTmp2);

   //username não foi encontrado, então retorna o valor -1 que é usado como condição para a impressão de mensagem informando a não existência do cliente na chamada da função (função logAsRoot.c)
   if (!encontrou){
      return -1;	   
   }
 
 
    //remove do diretório o arquivo arqFisicoClientes, pois este arquivo contém o cliente que foi removido
    remove(arqFisicoClientes);

   //renomeia o arquivo auxiliar tmp.bin (que não contém o cliente removido) para arqFisicoClientes. Assim, tem-se o arquivo arqFisicoClientes com o cliente removido    
    rename("tmp.bin", arqFisicoClientes);

    //remove do diretório o arquivo arqFisicoLogin, pois este arquivo contém o username que foi removido
    remove(arqFisicoLogin);

    //renomeia o arquivo auxiliar tmp2.bin (que não contém o username removido) para arqFisicoLogin. Assim, tem-se o arquivo arqFisicoLogin com o username removido
    rename("tmp2.bin", arqFisicoLogin); 
  
    return 0;    
}
