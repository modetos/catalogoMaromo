# Catalogo de Jogos Digitais

- Sabrina Aparecida Modesto
- Turma: ADS Noturno

## Justificativa

Escolhi esse tema por que é um assunto que eu me interesso e pareceu mais simples.

## Arquivos

- modulo.h: struct Jogo, constantes e protótipos das funções
- modulo.c: código das funções
- main.c: main e o menu
- dados.txt: onde os jogos ficam salvos


## Como funciona

Os jogos ficam em um vetor de ponteiros (`Jogo *vetor[MAX]`), com MAX = 100. Quando o programa abre, todas as posições apontam pra NULL. O malloc so e usado quando um jogo é cadastrado ou carregado do arquivo. No final o programa usa free em cada posição que não é NULL.

Se o dados.txt não existir o programa começa vazio.

Menu:

1. Cadastrar jogo
2. Listar todos
3. Buscar por codigo
4. Relatorio (jogo com maior tempo jogado)
5. Salvar e sair

No dados.txt cada linha é um jogo, com os campos separados por `;`:

```
codigo;titulo;desenvolvedora;preco;horas
```

Obs: não usar `;` no título nem na desenvolvedora porquê atrapalha a leitura do arquivo.
