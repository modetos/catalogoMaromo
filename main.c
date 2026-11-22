#include <stdio.h>
#include "modulo.h"

int main() {
    Jogo *vetor[MAX]; // cria um vetor com 100 posicoes, cada uma eh um ponteiro para um jogo.
    // nesse momento todos os vetores estao com lixo dentro.
    int opcao;

    inicializar(vetor); // chama a funcao criada no modulo.c que coloca NULL em cada posicao do vetor, tirando o lixo.
    carregar(vetor); // se ja existe um arquivo de dados.txt, ele le esse arquivo e coloca nos vetores (salvando
    //os jogos existentes.

    do {
        printf("\n===== CATALOGO DE JOGOS DIGITAIS =====\n");
        printf("1 - Cadastrar jogo\n");
        printf("2 - Listar todos\n");
        printf("3 - Buscar por codigo\n");
        printf("4 - Relatorio (maior tempo jogado)\n");
        printf("5 - Salvar e sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        switch (opcao) {
            case 1:
                cadastrar(vetor);
                break;
            case 2:
                listar(vetor);
                break;
            case 3:
                buscar(vetor);
                break;
            case 4:
                relatorio(vetor);
                break;
            case 5:
                salvar(vetor);
                liberar(vetor);
                printf("Ate mais!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
