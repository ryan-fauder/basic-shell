#include "historico.h"
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern const char _HISTORY_FILENAME[];
extern const int _HISTORY_INITIAL_CAPACITY;

void history_setRecord(History *history, char *record)
{
  // If last_record == record, so dont change the record
  if (strcmp(history_getRecord(history), record) == 0)
    return;

  
  if (history->capacity == history->size)
  {
    history_realloc(history, history->capacity + _HISTORY_INITIAL_CAPACITY);
  }

  stack_push(history->stack, record);
  history->size++;
}

char *history_getRecord(History *history)
{
  char *record = stack_get(history->stack);
  return record == NULL ? "" : record;
}

History *history_create()
{
  History *history = (History *)malloc(sizeof(History));

  history->stack = stack_create(_HISTORY_INITIAL_CAPACITY);
  history->size = 0;
  history->capacity = _HISTORY_INITIAL_CAPACITY;

  return history;
}

History *history_read()
{
  History *history = history_create();
  FILE *stream;
  stream = fopen(_HISTORY_FILENAME, "r+");

  if (stream == NULL)
  {
    printf("CREATING FILE FOR HISTORY\n");
    fclose(stream);

    stream = fopen(_HISTORY_FILENAME, "w");
    fclose(stream);
    
    return history;
  }

  int size;
  char *buffer = str_alloc();

  while(fscanf(stream, "%[^\n]", buffer) == 1)
  {
    fscanf(stream, "%*c");
    if (buffer == NULL)
    {
      printf("ERROR - HISTORY - COMMAND NOT FOUND ON READING FILE\n");
      fclose(stream);
      return NULL;
    }
    history_setRecord(history, buffer);
  }

  if (!feof(stream)){
    // IF IT'S NOT THE EOF
    printf("ERROR - HISTORY - WRONG FORMAT FOR HISTORY FILE\n");
    // RETURNS HISTORY
  }

  fclose(stream);
  return history;
}

void history_write(History *history)
{
  FILE *stream;

  stream = fopen(_HISTORY_FILENAME, "w");
  for (int i = 0; i < history->size; i++)
  {
    char *command = stack_at(history->stack, i);
    if (command == NULL)
    {
      printf("ERROR - HISTORY - COMMAND NOT FOUND IN STACK");
      return;
    }
    fprintf(stream, "%s\n", command);
  }

  fclose(stream);
}

void history_free(History *history)
{
  stack_free(history->stack);
  free(history);
}

void history_print(History *history)
{
  stack_print(history->stack);
}

void history_realloc(History *history, int newCapacity)
{
  stack_realloc(history->stack, newCapacity);
  history->capacity = newCapacity;
}

void history_test(){
  History * history = history_create();

  printf("%s\n", history_getRecord(history));
  history_setRecord(history, "COMMAND 1");
  history_setRecord(history, "COMMAND 2");
  history_setRecord(history, "COMMAND 2");
  history_setRecord(history, "COMMAND 3");
  printf("%s\n", history_getRecord(history));
  history_print(history);
  history_write(history);
  printf("PRINT AFTER WRITING\n");
  history = history_read();
  history_print(history);

  history_free(history);
}