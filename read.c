#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"
#include "utils.h"
extern const int _COMMAND_SIZE;

void tokenize(Reader *reader, char *string, char separator)
{
  char *pt;
  int separator_count = char_counter(string, separator);
  int size_vector = separator_count + 1;
  printf("Tamanho vetor tokenized : %d\n", size_vector);
  char **vector = (char **)malloc(size_vector * sizeof(char *));
  for (int i = 0; i < size_vector; i++)
  {
    vector[i] = (char *)malloc(_COMMAND_SIZE * sizeof(char));
  }
  pt = strtok(string, &separator);
  strcpy(vector[0], pt);

  int i = 1;
  while (pt != NULL)
  {
    pt = strtok(NULL, &separator);
    if (pt == NULL)
      break;

    strcpy(vector[i], pt);
    i++;
  }

  reader->tokens = vector;
  reader->length = i;
}

char *read_line()
{
  char *input = str_alloc();
  scanf("%[^\n]", input);
  scanf("%*c");
  return input;
}