/*
 * Cadastra os dados de login no arqFisicoLogin e os outros dados do cliente no arqFisicoCliente
 * Caso o username ja tenha sido cadastrado retorna valor de erro.
 */

#include "libLocadoras.h"

int cadastraCliente(char arqFisicoClientes[], char arqFisicoLogin[], char username[]){
    LogInfo tmp;
    Cliente c;
    FILE *arqLogin = fopen(arqFisicoLogin, "rb");
    //Verifica se o arquivo foi aberto corretamente
    if (arqLogin == NULL){
       return 1;
    }
    //Verifica se esse username já foi cadastrado
    while (fread(&tmp, sizeof(LogInfo), 1, arqLogin) !=0 ){
        if (strcmp(username, tmp.username) == 0)
        {
            //Retorna o código de erro para a funcao logAsRoot informar o erro ao usuario
            return -1;
        }        
    }
    //Fecha o arquivo apos verificação
    fclose(arqLogin);
    //Atribui os dados de login a uma variavel temporaria
    strcpy(c.login.username, username);
    printf("Insira a senha:");
    scanf("\n%[^\n]s", c.login.passwd);
    //Chama a função para gravar os dados de login no arqFisicoLogin
    gravarNewLogingInfo(arqFisicoLogin, c.login);
    printf("***Login inserido com sucesso.***\n");
    //Substitui a senha que será armazenada no arqFisicoClientes por ******
    strcpy(c.login.passwd, "*****");

    //Grava o resto dos dados do cliente
    printf("Agora vamos cadastrar o restante dos dados:");
    printf("\nNome:");
    scanf("\n%[^\n]s", c.nome);
    printf("\nSobrenome:");
    scanf("\n%[^\n]s", c.sobrenome);
    //Endereço
    printf("\nRua:");
    scanf("\n%[^\n]s", c.endereco.rua);
    printf("\nNumero:");
    scanf("%d", &c.endereco.numero);
    printf("\nComplemento:");
    scanf("\n%[^\n]s", c.endereco.complemento);
    printf("\nCidade:");
    scanf("\n%[^\n]s", c.endereco.cidade);
    printf("\nCEP:");
    scanf("%d", &c.endereco.cep);
    //Contato
    printf("\nFone:");
    scanf("\n%[^\n]s", c.contato.fone);
    printf("\nE-mail:");
    scanf("\n%[^\n]s", c.contato.email);
    //Data nascimento
    printf("Data de nascimento:\nDia:");
    scanf("%d", &c.dataNascimento.dia);
    printf("\nMes:");
    scanf("%d", &c.dataNascimento.mes);
    printf("\nAno:");
    scanf("%d", &c.dataNascimento.ano);
    //Atribui dados padrão
    c.numeroAvaliacoes = 0;
    
    //Chama a função para gravar os dados no arquivo fisico
    gravarCliente(arqFisicoClientes, c);

    return 0;
}
