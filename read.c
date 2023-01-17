#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"
#include "utils.h"
extern const int _COMMAND_SIZE;


void tokenize (char *command, char separator, reader *t) {
  char *pt;
  int separator_count = char_counter(command, separator);
  int size_vector = separator_count + 1;
// printf("Tamanho vetor tokenized : %d\n", size_vector);
/*
  char **vector = (char **) malloc(size_vector*sizeof(char*));
  for(int i = 0; i < size_vector; i++) {
    vector[i] = (char*) malloc(_COMMAND_SIZE*sizeof(char));
  }
*/
  char *strTemp = str_alloc();
  t->length = 0; // limpa reader para receber novos comandos
  pt = strtok (command, &separator);
  strcpy(strTemp, pt);
  pushReader(t, strTemp);
  // int i = 1;
  while(pt != NULL) {
    pt = strtok (NULL, &separator);
    if(pt == NULL) break;
    
    strcpy(strTemp, pt);
    pushReader(t, strTemp);
    // i++;
  }
}

char* read_line(char *input) {
  scanf("%[^\n]s", input);
  return input;
}

reader* createReader(int initial_size) {
  reader *r = (reader*) malloc(sizeof(reader));
  r->length = 0;
  r->max_length = initial_size;

  r->tokens = (char**) malloc((r->max_length)*sizeof(char*));
  return r;
}

void pushReader(reader *r, char *str) {
  if( r->length == r->max_length ) {
    // alocar mais memoria
    r->max_length += 10;
    r->tokens = (char**) realloc(r->tokens, (r->max_length)*sizeof(char*));
  }
  char *strAlloc = str_alloc();
  strcpy(strAlloc, str);
  r->length++;
  r->tokens[r->length - 1] = strAlloc;
  return ;
}

void popReader(reader *r) {
  if(r->length == 0) return;
  if(r->length > 0) r->length--; 
}

void freeReader(reader *r) {
  free(r->tokens);
  free(r);
}

void print_reader(reader *r) {
  printf("Tamanho reader : %d\n", r->length);
  for(int i = 0; i < r->length; i++) {
    printf("[%s]\n", r->tokens[i]);
  }
  printf("Fim print reader\n");
  return ;
}

char* concatTokens(reader *r) {
  char * strConcat = str_alloc();
  strcat(strConcat, "/");
  for(int i = 0; i < r->length; i++) {
    strcat(strConcat, r->tokens[i]);
    if(i != r->length - 1) {
      strcat(strConcat, "/");
    } 
  }
  return strConcat;
}