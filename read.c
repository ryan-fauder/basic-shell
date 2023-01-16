#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"
#include "utils.h"
extern const int _COMMAND_SIZE;


void tokenize (char *command, char separator, reader *t) {
  char *pt;
  int separator_count =  char_counter(command, separator);
  int size_vector = separator_count + 1;
  printf("Tamanho vetor tokenized : %d\n", size_vector);
  char **vector = (char **) malloc(size_vector*sizeof(char*));
  for(int i = 0; i < size_vector; i++) {
    vector[i] = (char*) malloc(_COMMAND_SIZE*sizeof(char));
  }
  pt = strtok (command, &separator);
  strcpy(vector[0], pt);

  int i = 1;
  while(pt != NULL) {
    pt = strtok (NULL, &separator);
    if(pt == NULL) break;
    
    strcpy(vector[i], pt);
    i++;
  }

  t->tokens = vector;
  t->length = i;
}

char* read_line(char *input) {
  scanf("%[^\n]s", input);
  return input;
}