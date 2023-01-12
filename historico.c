#include "historico.h"
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char _HISTORY_FILENAME[] = ".meushell.hst";
const int _HISTORY_INITIAL_CAPACITY = 128;

void history_setRecord(History *history, char *record)
{
  // If last_record == record, so dont change the record
  if (strcmp(history_getRecord(history), record) == 0)
    return;
  if (history->capacity == history->size)
  {
    history_realloc(history, history->capacity + _HISTORY_INITIAL_CAPACITY);
  }
  history->size++;
  stack_push(history->stack, record);
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
  FILE *f;
  f = fopen(_HISTORY_FILENAME, "r+");

  if (f == NULL)
  {
    printf("Falha");
    f = fopen(_HISTORY_FILENAME, "w");
    return history;
  }

  int size;
  char *record = strAlloc();

  fscanf(f, "%d", &size);

  fscanf(f, "%[^\n]", record);
  history_realloc(history, size);
  for (int i = 0; i < history->capacity; i++)
  {
    fscanf(f, "%[^\n]", record);
    history_setRecord(history, record);
    if (record == NULL)
    {
      printf("ERROR - HISTORY - COMMAND NOT FOUND ON READING FILE");
      return NULL;
    }
  }

  fclose(f);
  return history;
}

void history_write(History *history)
{
  FILE *f;

  f = fopen(_HISTORY_FILENAME, "w");
  fprintf(f, "%d\n", history->size);
  fprintf(f, "HISTORY: \n");
  for (int i = 0; i < history->size; i++)
  {
    char *command = stack_pop(history->stack);
    if (command == NULL)
    {
      printf("ERROR - HISTORY - COMMAND NOT FOUND IN STACK");
      return;
    }
    fprintf(f, "%s\n", command);
  }

  fclose(f);
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
}
