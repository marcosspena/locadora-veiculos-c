/*
 *Esta função garante que seja digitado o valor zero (a locadora não tem esta categoria de carro) ou o valor 1 (a locadora tem esta categoria de carro).
 *Esta função é utilizada no cadastramento e alteração de locadoras.
 */

#include "libLocadoras.h"
int setaCategoria(char categoria[]){
  int set;	
  do{
      printf("\n %s (0/1): ", categoria);
      scanf("%d", &set); 
   }while (set != 0 && set != 1);

   return set;
}

