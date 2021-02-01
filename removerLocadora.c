/*
 * Função para remover uma locadora baseada no id.
 * A remoção é feita no arquivo arqFisicoLocadoras.
 */

#include "libLocadoras.h"

void removerLocadora(char arqFisicoLocadoras[], int idLocadora){
  FILE *arqLocadora = fopen(arqFisicoLocadoras, "r+b");
  Locadora tmp;
  int verificadorLocadora = 0;

  //Verifica se o arquivo foi aberto corretamente
  if (arqLocadora == NULL){
    printf("\nERRO: Erro ao abrir arquivo de locadoras na funcao removerLocadora.\n");
    return;
  }
  //Abre/cria o arquivo tmp.bin para modo de escrita (w) e o associa a variável arqTmp, que é utilizada como backup, ou seja, para copiar as informações que não devem ser removidas (ou seja, aquela cujo id é diferente do id a ser removido) do arqFisicoLocadoras.
  FILE *arqTmp = fopen("tmp.bin", "wb");
  //Verifica se o arquivo foi aberto corretamente
  if (arqTmp == NULL){
    printf("\nErro ao abrir arquivo temporário auxiliar em removerLocadora.\n"); 
    return;
  }
  while (fread(&tmp, sizeof(Locadora), 1, arqLocadora) !=0 ){
    //Caso o id lido seja o mesmo que deve ser removido, ele não é copiado para o arquivo temporário
    if (idLocadora == tmp.id)
    {
      //Para verificar se o id existe, utilizamos o verificadorLocadora, caso não exista retorna erro depois
      verificadorLocadora = 1;
    }
    //Caso o id não seja o que já foi cadastrado, ele é copiado para o arquivo temporário
    else
    {
      fwrite(&tmp, sizeof(Locadora), 1, arqTmp);
    }
  }
  //Fecha os arquivos fisicos
  fclose(arqLocadora);
  fclose(arqTmp);
  //Caso não tenha encontrado essa locadora, imprime erro e retorna para a logAsRoot
  if (verificadorLocadora == 0)
  {
    printf("ERRO: Locadora nao cadastrada.\n");
    return;
  }

  //remove do diretório o arquivo arqFisicoLocadoras, pois este arquivo contém a locadora removida
  remove(arqFisicoLocadoras);

  //renomeia o arquivo auxiliar tmp.bin (que não contém a locadora removida) para arqFisicoLocadoras. Assim, tem-se o arquivo arqFisicoLocadoras com a locadora removida    
  rename("tmp.bin", arqFisicoLocadoras);
  printf("\n***Locadora Removida***");
  return;
}

