//libLocadoras.h é inclusa para que a função main tenha acesso às funções, registros e constantes definidos. 
#include "libLocadoras.h"

int main(){
  //arqFisicoRoot.bin armazena username (root) e senha (1234) do administrador.
  char arqFisicoRoot[] = "arqFisicoRoot.bin";
 
  //arqFisicoLogin.bin armazena username e senha dos clientes cadastrados.
  char arqFisicoLogin[] = "arqFisicoLogin.bin";

  //"arqFisicoClientes.bin armazena as informações sobre os clientes cadastrados.
  char arqFisicoClientes[] = "arqFisicoClientes.bin";

  //armazena as informações sobre as locadoras cadastradas.
  char arqFisicoLocadoras[] = "arqFisicoLocadoras.bin";
  
  printf("\n === Aluno: Marcos Gabriel RA: 1907212 === \n");

  int opt;
  do{	  
     //Função que mostra as opções para o usuário ao executar o programa	  
     menuLog();
     scanf("%d", &opt);
	  
     if (opt == 1){
        tryLogin(arqFisicoRoot, arqFisicoClientes, arqFisicoLogin, arqFisicoLocadoras);
     }
     else if (opt == 2) {
        listarLocadoras(arqFisicoLocadoras);
     }
  }while (opt != 0);

  return 0;
}
