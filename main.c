#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "historico.h"
#include "map.h"
#include "stack.h"
#include "utils.h"
#include "env.h"
#include "shell.h"

extern int _COMMAND_SIZE;
extern char _ENV_FILENAME[];


int main(int argc, char const *argv[])
{
  Env * env = env_read(_ENV_FILENAME);
  History * history = history_create();
  FILE * stream;
  char * hostname = str_alloc();
  char * current_dir = str_alloc();
  char * pid = str_alloc();
  gethostname(hostname, _COMMAND_SIZE);
  current_dir = getenv("PWD");
  sprintf(pid, "%d", getpid());
  
  env_setVar(env, "HOST", hostname);
  env_setVar(env, "SHELL", pid);
  env_setVar(env, "DTA", current_dir);
  env_setVar(env, "PRONTO", "$DTA \\>");

  if(argc == 1){
    stream = stdin;
  }
  else if(argc == 2){
    char *filename = str_alloc();
    strcpy(filename, argv[1]);
    stream = fopen(filename, "r+");
  }
  else{
    printf("ERROR - MAIS PARAMETROS DO QUE ESPERADOS\n");
    return 0;
  }

  interpreter(env, history, stream);
  history_write(history);
  env_write(env, _ENV_FILENAME);
  return 0;
}