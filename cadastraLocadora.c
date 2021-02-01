/*
 * Cadastra uma nova locadora no arquivo arqFisicoLocadoras
 * Caso ja esteja cadastrada solicita novo nome ou permite cancelar o cadastro
 */

#include "libLocadoras.h"

void cadastraLocadora(char arqFisicoLocadoras[]){
   Locadora tmp, locadora;
   char nomeLocadora[40];
   int idLocadora = 0;
   FILE *arqLocadora = fopen(arqFisicoLocadoras, "rb");
   ///Verifica se o arquivo foi aberto corretamente
   if (arqLocadora == NULL){
       printf("\nERRO: Erro ao abrir arquivo de locadoras na funcao cadastraLocadora.\n");
       return;
   }
   //Pede ao user para inserir o nome da locadora para verificar se já existe
   printf("Insira o nome da locadora que deseja cadastrar:");
   scanf("\n%[^\n]s", nomeLocadora);
   //Verifica se já existe alguma locadora com esse nome
   while (fread(&tmp, sizeof(Locadora), 1, arqLocadora) !=0 ){
        if (strcmp(nomeLocadora, tmp.nome) == 0)
        {
            //Retorna e avisa que já há esse nome cadastrado
            printf("ERRO: Já foi cadastrada uma locadora com esse nome.");
            return;
        }
        //Conta quantas locadoras existem no cadastro
        idLocadora++;        
   }
   //Fecha o arquivo físico
   fclose(arqLocadora);
   //Deixa o id da nova locadora como o próximo id da lista
   idLocadora++;
   //Salva o nome e o id
   strcpy(locadora.nome, nomeLocadora);
   locadora.id = idLocadora;
   //Grava o resto dos dados da locadora
   printf("Agora vamos cadastrar o restante dos dados:");
   //Endereço
   printf("\nRua:");
   scanf("\n%[^\n]s", locadora.endereco.rua);
   printf("\nNumero:");
   scanf("%d", &locadora.endereco.numero);
   printf("\nComplemento:");
   scanf("\n%[^\n]s", locadora.endereco.complemento);
   printf("\nCidade:");
   scanf("\n%[^\n]s", locadora.endereco.cidade);
   printf("\nCEP:");
   scanf("%d", &locadora.endereco.cep);
   //Contato
   printf("\nFone:");
   scanf("\n%[^\n]s", locadora.contato.fone);
   printf("\nE-mail:");
   scanf("\n%[^\n]s", locadora.contato.email);
   //Seta as categorias
   locadora.tipoDeCarro.pequeno = setaCategoria("pequeno");
   locadora.tipoDeCarro.medio = setaCategoria("medio");
   locadora.tipoDeCarro.grande = setaCategoria("grande");
   locadora.tipoDeCarro.conversivel = setaCategoria("conversivel");
   locadora.tipoDeCarro.premium = setaCategoria("premium");
   locadora.tipoDeCarro.minivan = setaCategoria("minivan");
   locadora.tipoDeCarro.SUV = setaCategoria("SUV");
   //Deixa as avaliacoes inicialmente com 0
   locadora.avaliacao.ruim = 0;
   locadora.avaliacao.bom = 0;
   locadora.avaliacao.excelente = 0;
   //Chama a função para gravar os dados no arquivo fisico
   gravarLocadora(arqFisicoLocadoras, locadora);

   printf("\n***Locadora cadastrada***\n");
   printf("\nId da locadora: %d", idLocadora);
   return;
}
