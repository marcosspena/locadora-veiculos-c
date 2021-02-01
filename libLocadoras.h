/** @file   libLocadoras - definição de constantes, registros e protótipos das funcões utilizadas
    @author Juliana de Santi
    @date   Setembro - 2018
*/

#ifndef _LIBLOCADORAS_H_ 
#define _LIBLOCADORAS_H_ 

#include <stdio.h>
#include <string.h>

//=============== Constantes =======================
#define MAX_USER 11 //número máximo de caracteres usado para username
#define MAX_PASSWD 9 //número máximo de caracteres utilizados para a senha

#define MAX_ENDERECO 50 //Quantidade carateres itilizados para o complemento (do endereço)
#define MAX_LOCADORAS 50//número máximo de locadoras que podem ser cadastradas
#define MAX_CLIENTES 50 //número máximo de clientes cadastrados
#define MAX_LOCADORAS_POR_CLIENTE 50//número de locadoras por cliente


//=============== Registros/structs =======================
//Registro para a definição do tipo Data
typedef struct data{
  int dia, mes, ano;
} Data;

//Registro para a definição do tipo Contatos
typedef struct contatos{
   char fone[18];
   char email[40];	
} Contatos;

//Registro para a definição do tipo Endereco
typedef struct endereco{
   char rua[MAX_ENDERECO];
   int numero;
   char complemento[MAX_ENDERECO];
   char cidade[MAX_ENDERECO];
   int cep; 
} Endereco;

//Registro para a definição do tipo AvaliacaoParaLocadora
typedef struct avaliacaoParaLocadora{
   int ruim; 
   int bom;
   int excelente;
} AvaliacaoParaLocadora;

//Registro para a definição das categorias de carros 
typedef struct categoria{
  //setado para 1 => tem esta categoria de carro
  //setado para 0 => não tem esta categoria de carro
  //só pode aceitar estes valores, ou seja, 0 e 1
   int pequeno;
   int medio;
   int grande;
   int conversivel;
   int premium;
   int minivan;
   int SUV;   
  	
} Categoria;

//Registro para a definição do tipo Locadora
typedef struct locadora{
   char nome[40];
   int id;
   Endereco endereco;
   Contatos contato;
   Categoria tipoDeCarro;  
   AvaliacaoParaLocadora avaliacao;
} Locadora;

//Registro para a definição do tipo AvaliacaoDoCliente
typedef struct avaliacaoDoCliente{
   char nomeLocadora[40];
   int avaliacaoLocadora;
} AvaliacaoDoCliente;


//Registro para a definição do tipo LogInfo, utilizado para guardar username e senha de cada usuário
typedef struct log{
   char username[MAX_USER]; 
   char passwd[MAX_PASSWD]; 
}LogInfo;


//Registro para a definição do tipo Cliente
typedef struct cliente{
   LogInfo login;
   char nome[30];
   char sobrenome[30];
   Endereco endereco;
   Contatos contato;
   AvaliacaoDoCliente vetAvaliacoes[MAX_LOCADORAS_POR_CLIENTE];
   int numeroAvaliacoes;
   Data dataNascimento;
} Cliente;

//Registro para a definição do tipo superUser
typedef struct superUser{
   LogInfo login;
} SuperUser;


//=============== Protótipos =======================

void menuLog();
void tryLogin(char arqFisicoRoot[], char arqFisicoClientes[], char arqFisicoLogin[], char arqFisicoLocadoras[]);
void logAsRoot(char arqFisicoClientes[],  char arqFisicoLogin[], char arqFisicoLocadoras[]);
void menuRoot();
void logAsNormalUser(char arqFisicoClientes[], char arqFisicoLocadoras[], LogInfo userLog);
void menuCliente(char username[]);
void visualizaDadosCliente(char arqFisicoClientes[], LogInfo userLog);
int avaliarLocadora(char arqFisicoLocadoras[], char nomeLocadora[]);
void atualizaAvaliacaoCliente(char arqFisicoClientes[], char usernameCliente[], char nomeRest[], int avaliacao);
void visualizarAvaliacoes(char arqFisicoClientes[], char usernameCliente[]);

int cadastraCliente(char arqFisicoClientes[], char arqFisicoLogin[], char username[]);
int alterarCliente(char arqFisicoClientes[], char usernameCliente[]);
int removerCliente(char arqFisicoClientes[], char arqFisicoLogin[], char username[]);
void gravarCliente(char arqFisicoClientes[], Cliente c);
void listarClientes(char arqFisicoClientes[]);

void gravarNewLogingInfo(char arqFisicoLogin[], LogInfo newUserLoginInfo);

void cadastraLocadora(char arqFisicoLocadoras[]);
int setaCategoria(char categoria[]);
void gravarLocadora(char arqFisicoLocadoras[], Locadora locadora);
void listarLocadoras(char arqFisicoLocadoras[]);
void alterarLocadora(char arqFisicoLocadoras[]);
void removerLocadora(char arqFisicoLocadoras[], int idLocadora);


#endif
