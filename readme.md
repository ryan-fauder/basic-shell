# Shell Simplificada

Um projeto um shell simplificada que realiza a criação de variáveis de ambientes e a interpretação de comandos de linha.

## Alunos

- Matheus Queiroz Rocha Barbosa
- Ryan Fernandes Auder Lopes
- Gabriel Gonçalves de Oliveira

## Como executar?

```bash
  make run main && ./main
```

## Github

Esse projeto está disponível no repositório:

[https://github.com/ryan-fauder/basic-shell/](https://github.com/ryan-fauder/basic-shell/)

## Configurações da Shell

Qualquer alteração de configuração da shell pode ser realizada no arquivo: config.c

## Questões de Projeto

### Entrada

Não foram tratados espaços à esquerda e à direita, por uma questão de simplicidade.
Os valores de variáveis de ambiente podem ser colocados entre aspas.

### Variáveis de ambiente

A shell pode criar variáveis de ambientes no formato:

```bash
  amb VAR=VALUE
```

Bem como, também é possível acessar o valor de uma variável de ambiente a partir do comando:

```bash
  amb $VAR
```

Ou todas as variáveis de ambiente:

```bash
  amb
```

### Histórico

O arquivo armazena o histórico de comandos executados na ordem do mais antigo para o mais recente. Como a estrutura para armazenar o histórico é uma pilha, essa ordem foi decidida por uma questão de otimização. Desse modo, a cada comando lido no arquivo, ele já pode ser empilhado no histórico.

## Tarefas

- [x] Checar se existe uma chave igual ao armazenar?
- [x] Tokenize não pode separar espaços dentro de "".
- [x] Variáveis dentro de Variáveis.
- [x] Lidar com ../ em CD.
- [x] Lidar com ./ em CD.
- [x] Lidar com "" no valor de variáveis
