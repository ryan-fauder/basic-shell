#include <stdio.h>
#include <string.h>
#include "historico.h"
#include "stack.h"
#include "utils.h"

int main(int argc, char const *argv[])
{
  History * history = history_create();
  printf("%s\n", history_getRecord(history));
  history_setRecord(history, "ADEDONHA");
  printf("%s\n", history_getRecord(history));
  history_setRecord(history, "OBABA");
  printf("%s\n", history_getRecord(history));
  history_setRecord(history, "OBABA");
  printf("%s\n", history_getRecord(history));
  history_setRecord(history, "ADEDONHADO");
  printf("%s\n", history_getRecord(history));
  history_print(history);
  history_write(history);
  printf("PRINT AFTER WRITING\n");
  history_print(history);
  history = history_read();
  history_print(history);

  history_free(history);
  return 0;
  
}
