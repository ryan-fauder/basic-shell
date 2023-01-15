#include "shell.h"
#include "read.h"
#include "utils.h"
#include <stdio.h>

void interpreter(Env *env, History *history, FILE *stream)
{
  char *nameShell;
  char *input;
  while(1){
    printf("\t\t");
    nameShell = env_getVar(env, "PRONTO"); // Talvez usar str_get
    printf("%s", nameShell);
    printf(" \\>");
    input = read_line();
    if(input == EOF) break;
    history_setRecord(history, input);
    if(parser_controller(input) == NULL) break;
  }
  return;

}