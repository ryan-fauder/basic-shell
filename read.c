#include <string.h>
#include <stdlib.h>
#include "read.h"
#include "utils.h"
#include "stack.h"
extern const int _COMMAND_SIZE;

void tokenize(char *command, char separator, Reader *t) {
  char *pt;
  int separator_count = char_counter(command, separator);
  int size_vector = separator_count + 1;

  char *strTemp = str_alloc();
  t->length = 0; // limpa Reader para receber novos comandos
  pt = strtok (command, &separator);
  strcpy(strTemp, pt);
  reader_push(t, strTemp);
  // int i = 1;
  while(pt != NULL) {
    pt = strtok (NULL, &separator);
    if(pt == NULL) break;
    
    strcpy(strTemp, pt);
    reader_push(t, strTemp);
    // i++;
  }
}

char *read_between(char *begin, char end, char *token, int *index)
{
  int i = *index;
  printf("BEGIN: %s\n", begin);
  printf("BEFORE \": %s\n", token);
  token[i] = *begin;
  begin++;
  i++;
  for (; *begin != end; begin++, i++)
  {
    token[i] = *begin;
  }
  token[i] = *begin;
  begin++;
  i++;
  *index = i;
  printf("AFTER \": %s\n", token);
  return begin;
}

Reader *tokenize1(char *str, char separator)
{
  Reader *tokens = reader_create(10);
  char *c = str;
  char *token = str_alloc();
  int i = 0;
  for (; *c != '\0'; c++, i++)
  {
    if (*c == 34)
    { // c = \"
      c = read_between(c, 34, token, &i);
    }
    else if (*c == separator)
    {
      token[i] = '\0';
      i++;
      reader_push(tokens, token);
      i = -1;
      token = str_alloc();
    }
    else
    {
      token[i] = *c;
    }
  }
  token[i] = '\0';
  reader_push(tokens, token);
  return tokens;
}

char *read_line(FILE * stream)
{
  char *input = str_alloc();
  input[0] = 0;
  if(fscanf(stream, "%[^\n]s", input) == EOF) return NULL;
  fscanf(stream, "%*c");
  return input;
}

Reader* reader_create(int initial_size) {
  Reader *r = (Reader*) malloc(sizeof(Reader));
  r->length = 0;
  r->max_length = initial_size;

  r->tokens = (char**) malloc((r->max_length)*sizeof(char*));
  return r;
}

void reader_realloc(Reader *r, int new_length){
  r->max_length = new_length;
  r->tokens = (char**) realloc(r->tokens, (r->max_length)*sizeof(char*));
}

void reader_push(Reader *r, char *str) {
  if( r->length == r->max_length ) {
    reader_realloc(r, r->length + 10);
  }
  char *strAlloc = str_alloc();
  strcpy(strAlloc, str);
  r->length++;
  r->tokens[r->length - 1] = strAlloc;
  return ;
}

void reader_pop(Reader *r) {
  if(r->length > 0) r->length--;
}

void reader_free(Reader *r) {
  free(r->tokens);
  free(r);
}

void reader_print(Reader *r) {
  printf("Tamanho Reader : %d\n", r->length);
  for(int i = 0; i < r->length; i++) {
    printf("[%s]\n", r->tokens[i]);
  }
  printf("Fim print Reader\n");
  return ;
}

char* reader_join(Reader *r, char * separator) {
  char * strConcat = str_alloc();
  for(int i = 0; i < r->length; i++) {
    int token_len = strlen(r->tokens[i]);
    if(token_len == 0 && i != 0) continue;
    strcat(strConcat, r->tokens[i]);
    if(i != r->length - 1) {
      strcat(strConcat, separator);
    } 
  }
  // printf("[%s]\n", strConcat);
  return strConcat;
}