/*
 * Função responsável pela verificação e gerenciamento das chamadas paras funções que realizam o login do administrador e dos clientes.
 */

#include "libLocadoras.h"

void tryLogin(char arqFisicoRoot[], char arqFisicoClientes[], char arqFisicoLogin[], char arqFisicoLocadoras[]){
   char user[11], userArq[11]; 
   char senha[9], senhaArq[9]; 
   printf("\nusername: ");
   scanf("\n%[^\n]s", user); 
   printf("senha: ");
   scanf("\n%[^\n]s", senha);
 
   FILE *arq = fopen (arqFisicoRoot, "rb");
   if (arq == NULL){
       printf("\nErro ao abrir arquivo de root na funcao tryLogin.\n");
       return;
   }

   FILE *arqL = fopen (arqFisicoLogin, "rb");
   if (arqL == NULL){
       printf("\nErro ao abrir arquivo de login na funcao tryLogin.\n");
       return;
   }
   

   LogInfo root;
   //Faz a leitura das informações do root no arquivo arqFisicoRoot 
   fread(&root, sizeof(LogInfo), 1, arq);
   //Verifica se o usuário que está tentado logar é root e senha confere
   if (strcmp(user, root.username) == 0 && strcmp(senha, root.passwd) == 0){
       //loga como root	   
       logAsRoot(arqFisicoClientes, arqFisicoLogin, arqFisicoLocadoras);
   }
   //Tentative de log pelo usuário root, mas senha incorreta
   else if (strcmp(user, root.username) == 0 && strcmp(senha, root.passwd) != 0){
       printf("\n***Senha de root incorreta.***\n");	   
   }
   else{
       int encontrou = 0;
       int arquivoVazio = 1;
       LogInfo userLog;
       //Faz leitura no arquivo arqFisicoLogin para verificar se o usuário que está tentando realizar log está cadastrado e se a senha digita         da confere com a senha cadastrada
       while (fread(&userLog, sizeof(LogInfo), 1, arqL) != 0 && !encontrou){
	   arquivoVazio = 0;//se entrou no laço, então arquivo não está vazio    
           if (strcmp(user, userLog.username) == 0 && strcmp(senha, userLog.passwd) == 0){
	      //loga como cliente	   
              logAsNormalUser(arqFisicoClientes, arqFisicoLocadoras, userLog);
              encontrou  = 1;
           }
	   //Tentativa de log por usuário cadastrado, mas senha incorreta
	   else if (strcmp(user, userLog.username) == 0 && strcmp(senha, userLog.passwd) != 0){
	      printf("\n***Senha incorreta para %s.***\n",user);
              encontrou = 1;	      
	   } 
       }
       //usuário não cadastrado
       if (!encontrou || arquivoVazio){
	  printf("\n***Usuario %s não cadastrado.***\n",user);
       }
   }

   fclose(arq);
   fclose(arqL);

}
