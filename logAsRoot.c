/*
 * Função para chamada das funções as quais são relacionadas com o usuário root
 * As opções são mostradas com a função menuRoot e qual delas é chamada é por meio do while. 
 */


//libLocadoras.h é inclusa para que a função logAsRoot tenha acesso às definições de registros, funções e constantes
#include "libLocadoras.h"
void logAsRoot(char arqFisicoClientes[], char arqFisicoLogin[], char arqFisicoLocadoras[]){
    printf("\n**** Bem vindo root **** \n");
    int opt, idLocadora, retornoCadastro, retornoAlteraCliente, retornoRemoverCliente;
    char username[MAX_USER];
    
    menuRoot();
    scanf("%d", &opt);
    while (opt != 9){
        switch (opt)
        {
        case 1:
            printf("Insira o username do cliente a ser cadastrado: ");
            scanf("\n%[^\n]s", username);
            retornoCadastro = cadastraCliente(arqFisicoClientes, arqFisicoLogin, username);
            switch (retornoCadastro)
            {
            case -1:
                printf("\nERRO: Username ja cadastrado.");
                break;
            case 0:
                printf("\n***Cliente cadastrado***\n");
                break;
            case 1:
                printf("\nERRO: Erro ao abrir arquivo de login na funcao cadastraCliente.");
                break;
            default:
                break;
            }
            break;
        case 2:
            cadastraLocadora(arqFisicoLocadoras);
            break;
        case 3:
            printf("Insira o username do cliente a ser alterado: ");
            scanf("\n%[^\n]s", username);
            retornoAlteraCliente = alterarCliente(arqFisicoClientes, username);
            switch (retornoAlteraCliente)
            {
            case -1:
                printf("\nERRO: Username nao cadastrado.");
                break;
            case 0:
                printf("\n***Dados do cliente alterado***\n");
                break;
            case 1:
                printf("\nERRO: Erro ao abrir arquivo de clientes na funcao alteraCliente.");
                break;
            case 2:
                printf("\nERRO: Operacao cancelada pelo usuario.");
                break;
            default:
                break;
            }
            break;
        case 4:
            alterarLocadora(arqFisicoLocadoras);
            break;
        case 5:
            printf("Insira o username do cliente a ser removido: ");
            scanf("\n%[^\n]s", username);
            retornoRemoverCliente = removerCliente(arqFisicoClientes, arqFisicoLogin, username);
            switch (retornoRemoverCliente)
            {
            case -1:
                printf("\nERRO: Username nao cadastrado.");
                break;
            case 0:
                printf("\n***Cliente removido***\n");
                break;
            case 1:
                break;
            default:
                break;
            }
            break;
        case 6:
            printf("Insira o id da locadora a ser removida: ");
            //Verifica se o scanf retorna um inteiro
            if (scanf("%d", & idLocadora) != 1)
            {
                //Impede loop infinito por scanf
                getchar();
                printf("\nERRO: Insira um valor inteiro para o id\n");
                break;
            }
            removerLocadora(arqFisicoLocadoras, idLocadora);
            break;
        case 7:
            listarClientes(arqFisicoClientes);
            break;
        case 8:
            listarLocadoras(arqFisicoLocadoras);
            break;
        default:
            break;
        }

        menuRoot();
        scanf("%d", &opt);
    }
}

