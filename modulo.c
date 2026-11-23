#include <stdio.h>
#include <stdlib.h> //malloc e free
#include <string.h> //strlen
#include "modulo.h" //struct e prototipos

/* fiz muitas anotacoes pq usei IA para me ajudar nessa parte, me desculpa se ficou muito poluido! */

/* coloca NULL em todas as posicoes do vetor */
void inicializar(Jogo *vetor[]) {
    int i;
    for (i = 0; i < MAX; i++) {
        vetor[i] = NULL; // null = essa posicao esta vazia
    }
}

/* le o arquivo dados.txt e coloca cada linha no vetor */
void carregar(Jogo *vetor[]) {
    FILE *arq; // cria um ponteiro para file
    char linha[200];
    int i = 0; // proxima posicao livre do vetor, qnd um jogo eh salvo, ele aumenta
    int resultado; // quantos campos sscanf leu
    Jogo *novo; // cria um ponteiro para jogo

    arq = fopen(NOME_ARQUIVO, "r"); // file guarda a acao de abrir o dados.txt
    if (arq == NULL) {
        /* se o arquivo nao existe o sistema comeca vazio */
        return;
    }

    while (fgets(linha, 200, arq) != NULL && i < MAX) { //enquanto a linha nao for vazia e contador menor que
        // o numero maximo de jogos, le 200 caracteres dessa linha e guarda na variavel/vetor linha

        novo = malloc(sizeof(Jogo)); // reserva um espaco de memoria do tamanho de jogo e armazena em novo

        /* o sscanf devolve quantos campos ele leu, cada linha tem 5 campos */
        resultado = sscanf(linha, "%d;%[^;];%[^;];%f;%f", &novo->codigo, novo->titulo,
                           novo->desenvolvedora, &novo->preco, &novo->horas);

        // esse bloco de cima desmonta a linha lida separando por ;, %d le o codigo, %[^;] le o texto ate ; e %f
        //as horas jogadas e preco do jogo, ai armazena cada informacao nas variaveis da struct. o >numero de campos
        //preenchidos< fica guardado em resultado.

        if (resultado == 5) {
            vetor[i] = novo; // se todos os 5 campos foram preenchidos ele coloca o jogo no vetor e avanca o contador.
            i++;
        } else {
            /* linha errada, entao libera o que alocou */
            free(novo); //se tiver algo errado na linha ele libera tudo
        }
    }

    fclose(arq);
}

/* grava todos os jogos no arquivo texto */
void salvar(Jogo *vetor[]) {
    FILE *arq;
    int i;

    arq = fopen(NOME_ARQUIVO, "w");
    if (arq == NULL) { // se nao houver arquivo dados.txt
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }

    for (i = 0; i < MAX; i++) {
        if (vetor[i] != NULL) {
            fprintf(arq, "%d;%s;%s;%.2f;%.1f\n", vetor[i]->codigo, vetor[i]->titulo,
                    vetor[i]->desenvolvedora, vetor[i]->preco, vetor[i]->horas);
        }
    }

    fclose(arq);
    printf("Dados salvos em %s\n", NOME_ARQUIVO);
}

void cadastrar(Jogo *vetor[]) {
    int i;
    Jogo *novo;

    /* procura a primeira posicao que esta NULL */
    i = 0;
    while (i < MAX && vetor[i] != NULL) {
        i++;
    }

    if (i == MAX) {
        printf("O catalogo esta cheio!\n");
        return;
    }

    // se o computador estiver sem memoria/por alguma razao malloc falhar, exibe a mensagem
    novo = malloc(sizeof(Jogo));
    if (novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    /* -> para chegar nos campos da struct */
    printf("Codigo: ");
    scanf("%d", &novo->codigo);
    getchar();  // limpa buffer

    printf("Titulo: ");
    fgets(novo->titulo, TAM_TITULO, stdin);
    novo->titulo[strlen(novo->titulo) - 1] = '\0';  /* tira o \n do final */

    printf("Desenvolvedora: ");
    fgets(novo->desenvolvedora, TAM_DEV, stdin);
    novo->desenvolvedora[strlen(novo->desenvolvedora) - 1] = '\0';

    printf("Preco: ");
    scanf("%f", &novo->preco);

    printf("Horas jogadas: ");
    scanf("%f", &novo->horas);
    getchar();

    vetor[i] = novo;
    printf("Jogo cadastrado!\n");
}

void listar(Jogo *vetor[]) {
    int i;
    int achou = 0;

    printf("\n--- Lista de jogos ---\n");
    for (i = 0; i < MAX; i++) {
        if (vetor[i] != NULL) {
            printf("Codigo: %d\n", vetor[i]->codigo);
            printf("Titulo: %s\n", vetor[i]->titulo);
            printf("Desenvolvedora: %s\n", vetor[i]->desenvolvedora);
            printf("Preco: R$ %.2f\n", vetor[i]->preco);
            printf("Horas jogadas: %.1f\n", vetor[i]->horas);
            printf("----------------------\n");
            achou = 1;
        }
    }

    if (achou == 0) {
        printf("Nenhum jogo cadastrado.\n");
    }
}

void buscar(Jogo *vetor[]) {
    int i;
    int codigo;
    int achou = 0;

    printf("Digite o codigo do jogo: ");
    scanf("%d", &codigo);
    getchar();

    for (i = 0; i < MAX; i++) {
        if (vetor[i] != NULL && vetor[i]->codigo == codigo) {
            printf("\nJogo encontrado!\n");
            printf("Codigo: %d\n", vetor[i]->codigo);
            printf("Titulo: %s\n", vetor[i]->titulo);
            printf("Desenvolvedora: %s\n", vetor[i]->desenvolvedora);
            printf("Preco: R$ %.2f\n", vetor[i]->preco);
            printf("Horas jogadas: %.1f\n", vetor[i]->horas);
            achou = 1;
        }
    }

    if (achou == 0) {
        printf("Jogo nao encontrado.\n");
    }
}

/* relatorio: jogo com maior tempo jogado */
void relatorio(Jogo *vetor[]) {
    int i;
    int posMaior = -1;
    float maior = -1;

    for (i = 0; i < MAX; i++) {
        if (vetor[i] != NULL && vetor[i]->horas > maior) {
            maior = vetor[i]->horas;
            posMaior = i;
        }
    }

    if (posMaior == -1) {
        printf("Nenhum jogo cadastrado para gerar o relatorio.\n");
    } else {
        printf("\n--- Jogo com maior tempo jogado ---\n");
        printf("Titulo: %s\n", vetor[posMaior]->titulo);
        printf("Desenvolvedora: %s\n", vetor[posMaior]->desenvolvedora);
        printf("Horas jogadas: %.1f\n", vetor[posMaior]->horas);
    }
}

/* da free em cada posicao que nao e NULL */
void liberar(Jogo *vetor[]) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (vetor[i] != NULL) {
            free(vetor[i]);
        }
    }
}
