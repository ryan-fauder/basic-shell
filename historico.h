#ifndef __HISTORICO_H__
#define __HISTORICO_H__
#include "stack.h"

typedef struct
{
  Stack *stack;
  int size;
  int capacity;
} History;

History *history_create();
void history_setRecord(History *history, char *record);
char *history_getRecord(History *history);
History *history_read();
void history_write(History *history);
void history_print(History *history);
void history_free(History *history);
void history_realloc(History *history, int newCapacity);
void history_test();

#endif //__HISTORICO_H__