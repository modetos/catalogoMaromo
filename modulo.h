#ifndef MODULO_H // se o modulo.h ainda nao foi definido
#define MODULO_H // entao ele define, mas se ja foi, nao define.

/* Catalogo de Jogos Digitais */

#define MAX 100 // o catalogo so guarda no maximo 100 jogos.
#define TAM_TITULO 50 // o titulo guarda so 50 letras.
#define TAM_DEV 50 // e a desenvolvedora tambem.
#define NOME_ARQUIVO "dados.txt" // define o nome do arquivo onde os dados sao lidos.

typedef struct { // define a struct, um grupo de variaveis de diferentes tipos
    int codigo;
    char titulo[TAM_TITULO];
    char desenvolvedora[TAM_DEV];
    float preco;
    float horas;
} Jogo; // nomeia essa struct "jogo"

// jogo *vetor[max] --> guarda o endereco de memoria da variavel onde fica um jogo em cada uma das posicoes
void inicializar(Jogo *vetor[]); // chama a funcao que coloca null em todas a posicoes do vetor.
void carregar(Jogo *vetor[]);
void salvar(Jogo *vetor[]);
void cadastrar(Jogo *vetor[]);
void listar(Jogo *vetor[]);
void buscar(Jogo *vetor[]);
void relatorio(Jogo *vetor[]);
void liberar(Jogo *vetor[]);

#endif
