/*
* Função que permite ao root alterar endereço, contatos e/ou categorias de veiculo da locadora selecionada
* Caso nao encontre a locadora ou o arquivo nao abra, imprime as mensagens de erro direto na função
*/

#include "libLocadoras.h"

void alterarLocadora(char arqFisicoLocadoras[]){
  FILE *arqLocadora = fopen(arqFisicoLocadoras, "r+b");
  Locadora tmp;
  int verificadorLocadora = 0, posicao = 0, opt, idLocadora, validadorInteiro = 0;

  //Verifica se o arquivo foi aberto corretamente
  if (arqLocadora == NULL){
    printf("\nERRO: Erro ao abrir arquivo de locadoras na funcao alterarLocadora.\n");
    return;
  }
  //Solicita ao root o id da locadora para ser alterada
  //Para evitar que o programa trave, só permitimos id do tipo int
  
  printf("Insira o id da locadora que deseja alterar:");
  //Verifica se o scanf retorna um inteiro
  if (scanf("%d", & idLocadora) != 1)
  {
    //Impede loop infinito por scanf
    getchar();
    printf("\nERRO: Insira um valor inteiro para o id\n");
    return;
  }
  
  //Verifica se esse id já foi cadastrado
  while (fread(&tmp, sizeof(Locadora), 1, arqLocadora) !=0 ){
    if (idLocadora == tmp.id)
    {
      //Caso encontre o id na base de dados o verificador fica 1
      verificadorLocadora = 1;
      //Pergunta o que deseja alterar no cadastro
      //Impede que seja digitado valor diferente de 1, 2, 3 e 0
      do
      {
        printf("Qual dado deseja alterar:\n");
        printf("1 - Endereço\n");
        printf("2 - Contato\n");
        printf("3 - Categoria de veiculos\n");
        printf("0 - Cancelar\n");
        scanf("%d", &opt);
      }while (opt !=1 && opt !=2 && opt !=3 && opt !=0);
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
      case 3:
        tmp.tipoDeCarro.pequeno = setaCategoria("pequeno");
        tmp.tipoDeCarro.medio = setaCategoria("medio");
        tmp.tipoDeCarro.grande = setaCategoria("grande");
        tmp.tipoDeCarro.conversivel = setaCategoria("conversivel");
        tmp.tipoDeCarro.premium = setaCategoria("premium");
        tmp.tipoDeCarro.minivan = setaCategoria("minivan");
        tmp.tipoDeCarro.SUV = setaCategoria("SUV");
        break;
      case 0:
        printf("\nERRO: Operacao cancelada pelo usuario.");
        return;
        break;
      default:
        break;
      }
      //Vai com o ponteiro para a posição do dado correto
      fseek(arqLocadora, posicao*sizeof(Locadora), SEEK_SET);
      //Substitui a informação cadastrada
      fwrite(&tmp, sizeof(Locadora), 1, arqLocadora);
      //Fecha o arquivo fisico
      fclose(arqLocadora);
    }
    //Encontra a posição do dado para usar a função fseek depois
    posicao++;
  }
  //Caso não tenha encontrado essa locadora, imprime erro e retorna para a logAsRoot
  if (verificadorLocadora == 0)
  {
    fclose(arqLocadora);
    printf("ERRO: Locadora nao cadastrada.\n");
    return;
  }
  printf("\n***Dados da locadora alterado***\n");
  return;
}
