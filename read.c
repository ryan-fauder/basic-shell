#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"

#define LENGTH_INPUT 50

char input[LENGTH_INPUT];

void clear_input() {
  int i = 0;
  while(i < LENGTH_INPUT) {
    input[i] = '\0';
    i++;
  }
}

int string_length(char *str) {
  int i = 0;
  while(str[i] != '\0') i++;
  return i;
}

int space_counter(char *str) {
  int i = 0, count = 0;
  while(str[i] != '\0') {
    if(str[i] == ' ') count ++;
    i++;
  }
  return count;
}

char** tokenize (char *command, tokens *t) {
  char *pt;
  char **vector_tokenize;
  int length = string_length(command);
  int space_count = space_counter(command);
  int size_vector = 0;

  size_vector = space_count + 1;
 
  char **vector = (char **) malloc(size_vector*sizeof(char*));
  for(int i = 0; i < size_vector; i++) {
    vector[i] = (char*) malloc(LENGTH_INPUT*sizeof(char));
  }
  pt = strtok (command, " ");
  strcpy(vector[0], pt);

  int i = 1;
  while(pt != NULL) {
    pt = strtok (NULL, " ");
    if(pt == NULL) break;
    
    strcpy(vector[i], pt);
    i++;
  }

  t->tokens = vector;
  t->length = i;
  return vector_tokenize;
}

char* read_line() {
  scanf("%[^\n]s", input);
  return input;
}

int main() {
  char *line;
  tokens t;
  clear_input();
  line = read_line();
  tokenize(line, &t);
  
  printf("Quantidade de Comandos : %d\n", t.length);
  for(int i = 0; i < t.length; i++) {
    printf("String [%s]\n", t.tokens[i]);
  }
  return 0;
}