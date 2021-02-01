/*
 * Atualiza a avaliação feita pelo cliente no arquivo arqFisicoClientes
 */

#include "libLocadoras.h"

void atualizaAvaliacaoCliente(char arqFisicoClientes[], char usernameCliente[], char nomeLocadora[], int avaliacao){
    FILE *arqCliente = fopen(arqFisicoClientes, "r+b");
    Cliente tmp;
    int posicao = 0, i = 0, verificadorLocadora = 0;

    //Verifica se o arquivo foi aberto corretamente
    if (arqCliente == NULL){
        printf("ERRO: Erro ao abrir arquivo arqFisicoClientes em atualizaAvaliacaoCliente");
        return;
    }
    //Verifica se esse cliente já avaliou essa locadora
    while (fread(&tmp, sizeof(Cliente), 1, arqCliente) !=0 ){
        if (strcmp(usernameCliente, tmp.login.username) == 0)
        {   
            //Confere se ele já fez alguma avaliação
            if (tmp.numeroAvaliacoes > 0){
                //Confere as avaliacoes desse cliente  
                for (i = 0; i < tmp.numeroAvaliacoes; i++)
                {
                //Ve se ele ja avaliou essa locadora
                if (strcmp(nomeLocadora, tmp.vetAvaliacoes[i].nomeLocadora) == 0)
                {
                    tmp.vetAvaliacoes[i].avaliacaoLocadora = avaliacao;
                    strcpy(tmp.vetAvaliacoes[i].nomeLocadora, nomeLocadora);
                    verificadorLocadora = 1;
                }  
                }
                if (verificadorLocadora == 0)
                {
                    tmp.vetAvaliacoes[tmp.numeroAvaliacoes].avaliacaoLocadora = avaliacao;
                    strcpy(tmp.vetAvaliacoes[tmp.numeroAvaliacoes].nomeLocadora, nomeLocadora);
                    tmp.numeroAvaliacoes++;
                }
            }
            else
            {
                tmp.numeroAvaliacoes++;
                tmp.vetAvaliacoes[0].avaliacaoLocadora = avaliacao;
                strcpy(tmp.vetAvaliacoes[0].nomeLocadora, nomeLocadora);
            }
            
            //Vai com o ponteiro para a posição do dado correto
            fseek(arqCliente, posicao*sizeof(Cliente), SEEK_SET);
            //Substitui a informação cadastrada
            fwrite(&tmp, sizeof(Cliente), 1, arqCliente);
            //"Desfaz" o fseek e faz o ponteiro avançar
            fseek(arqCliente, (posicao+1)*sizeof(Cliente), SEEK_SET);
        }
        //Encontra a posição do dado para usar a função fseek depois
        posicao++;
    }
    //Fecha o arquivo fisico
    fclose(arqCliente);
    //Avisa o usuário que a avaliação foi concluída
    printf("\n***Avaliacao concluida***\n");
    return;
}
