#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sysexits.h>
#include <errno.h>
#include <sys/wait.h>
#include "historico.h"
#include "map.h"
#include "stack.h"
#include "utils.h"

int main(int argc, char const *argv[])
{
  history_test();
  map_test();
  pair_test();


  
  Map *map = map_create(100);
  char *command = "ls";
  map_set(map, str_get("DTA"), str_get("/home/ryan"));
  char *arg = map_get(map, "DTA");
  char **args = (char **)malloc(sizeof(char *) * 32);
  int pid, status, ret;
  if ((pid = fork()) < 0)
  {
    perror("fork");
    exit(EX_OSERR);
  }

  if (!pid)
  {
    args[0] = "cd";
    args[1] = arg;
    execvp(command, args);
    args[0] = "ls";
    args[1] = NULL;
    execvp(command, args);
  }
  waitpid(pid, &status, 0);
  return 0;
}
