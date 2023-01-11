#include <stdio.h>
#include "historico.h"

int main(int argc, char const *argv[])
{
  History * history = readHistory();
  printf("%s\n", getRecord(history));
  setRecord(history, "ADEDONHA");
  printf("%s\n", getRecord(history));
  setRecord(history, "OBABA");
  printf("%s\n", getRecord(history));
  setRecord(history, "OBABA");
  printf("%s\n", getRecord(history));
  setRecord(history, "ADEDONHADO");
  printf("%s\n", getRecord(history));
  freeHistory(history);
  return 0;
  
}
