/*
 * Função responsável por gerenciar as chamadas para as funções que realizam as operações do cliente logado.
 */

#include "libLocadoras.h"
void logAsNormalUser(char arqFisicoClientes[], char arqFisicoLocadoras[], LogInfo userLog){
    int opt;
    
    printf("\n**** Bem vindo %s **** \n", userLog.username);

    menuCliente(userLog.username); 
    scanf("%d", &opt);
    while (opt != 6){
      switch(opt){
         case 1: visualizaDadosCliente(arqFisicoClientes, userLog);
               break;
         case 2: alterarCliente (arqFisicoClientes, userLog.username);
            break;
         case 3: listarLocadoras(arqFisicoLocadoras);
            break;
         case 4: printf("\nNome da locadora a avaliar: ");
            char nomeLocadora[40];  
            scanf("\n%[^\n]s", nomeLocadora); 
            int avaliacao = avaliarLocadora(arqFisicoLocadoras, nomeLocadora);
            if (avaliacao == -1){
               printf("\nLocadora %s nao cadastrada\n", nomeLocadora);	  
            }
            else if (avaliacao >1 && avaliacao < 5){
               atualizaAvaliacaoCliente(arqFisicoClientes, userLog.username, nomeLocadora, avaliacao);
            }
            break;
         case 5: visualizarAvaliacoes(arqFisicoClientes, userLog.username);
            break;
      }

      menuCliente(userLog.username); 
      scanf("%d", &opt);
   }

}

