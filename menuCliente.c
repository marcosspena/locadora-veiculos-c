/*
 * Esta função lista as operações que podem ser realizadas pelo cliente logado.
 */

#include "libLocadoras.h"
void menuCliente(char username[]){
   printf("\n==== %s =====", username);
   printf("\n1 - Visualizar meus dados.");
   printf("\n2 - Alterar meus dados.");
   printf("\n3 - Listar todas as locadoras.");
   printf("\n4 - Avaliar locadora.");
   printf("\n5 - Visualizar minhas avaliacoes.");
   printf("\n6 - Logout.");
   printf("\n=======================\n");
}
