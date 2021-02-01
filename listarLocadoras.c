/*
 *  Função para listar todas as locadoras cadastrados no arqFisicoLocadoras e suas respectivas informações
 */

#include "libLocadoras.h"

void listarLocadoras(char arqFisicoLocadoras[]){
    FILE *arqLocadora = fopen(arqFisicoLocadoras, "rb");
    Locadora tmp;
    int i, totalAvaliacoes;
    //Verifica se o arquivo foi aberto corretamente
    if (arqLocadora == NULL){
        printf("ERRO: Erro ao abrir arquivo arqFisicoLocadoras na funcao listarLocadoras");
        return;
    }
    printf("***Imprimindo lista de locadoras***\n\n");
    //Para cada locadora, imprime as informações dela
    while (fread(&tmp, sizeof(Locadora), 1, arqLocadora) !=0){
        printf("\nNome: %s", tmp.nome);
        printf("\nId: %d", tmp.id);
        //Endereço
        printf("\nRua: %s", tmp.endereco.rua);
        printf("\nNumero: %d", tmp.endereco.numero);
        printf("\nComplemento: %s", tmp.endereco.complemento);
        printf("\nCidade: %s", tmp.endereco.cidade);
        printf("\nCEP: %d", tmp.endereco.cep);
        //Contato
        printf("\nFone: %s", tmp.contato.fone);
        printf("\nE-mail: %s", tmp.contato.email);
        //Categorias
        printf("\nCarro pequeno(0/1): %d ", tmp.tipoDeCarro.pequeno);
        printf("\nCarro medio(0/1): %d", tmp.tipoDeCarro.medio);
        printf("\nCarro grande(0/1): %d", tmp.tipoDeCarro.grande);
        printf("\nCarro conversivel(0/1): %d", tmp.tipoDeCarro.conversivel);
        printf("\nCarro premium(0/1): %d", tmp.tipoDeCarro.premium);
        printf("\nCarro minivan(0/1): %d", tmp.tipoDeCarro.minivan);
        printf("\nCarro SUV(0/1): %d", tmp.tipoDeCarro.SUV);
        //Calcula o total de avaliações
        totalAvaliacoes = tmp.avaliacao.bom + tmp.avaliacao.excelente + tmp.avaliacao.ruim; 
        //Mostra as avaliações
        printf("\nTotal de avaliacoes: %d", totalAvaliacoes);
        printf("\nRuim: (%d/%d)", tmp.avaliacao.ruim, totalAvaliacoes);
        printf("\nBom: (%d/%d)", tmp.avaliacao.bom, totalAvaliacoes);
        printf("\nExcelente: (%d/%d)", tmp.avaliacao.excelente, totalAvaliacoes);
        //Pula linhas antes da próxima locadora para facilitar a visualização
        printf("\n\n");
    }
    //Fecha o arquivo fisico
    fclose(arqLocadora);
    return;
}
