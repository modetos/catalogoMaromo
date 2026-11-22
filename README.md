# Catalogo de Jogos Digitais

## Dupla

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

Os jogos ficam em um vetor de ponteiros (`Jogo *vetor[MAX]`), com MAX = 100. Quando o programa abre, todas as posicoes apontam pra NULL. O malloc so e usado quando um jogo e cadastrado ou carregado do arquivo. No final o programa usa free em cada posicao que nao e NULL.

Se o dados.txt nao existir o programa comeca vazio.

Menu:

1. Cadastrar jogo
2. Listar todos
3. Buscar por codigo
4. Relatorio (jogo com maior tempo jogado)
5. Salvar e sair

No dados.txt cada linha e um jogo, com os campos separados por `;`:

```
codigo;titulo;desenvolvedora;preco;horas
```

Obs: nao usar `;` no titulo nem na desenvolvedora porque atrapalha a leitura do arquivo.
