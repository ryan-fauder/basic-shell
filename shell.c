#include "shell.h"
#include "parser.h"
#include "read.h"
#include "utils.h"
#include <stdio.h>

void interpreter(Env *env, History *history, FILE *stream)
{
  char *nameShell;
  char *input;
  while(1){
    if(stream == stdin){
      nameShell = env_getVar(env, "PRONTO"); // Talvez usar str_get
      printf("%s", nameShell);
    }
    input = read_line(stream);
    if(input == NULL) break;
    history_setRecord(history, input);
    printf("%s\n", input);
    if(parser_controller(env, input) == NULL) break;
  }
  return;
}