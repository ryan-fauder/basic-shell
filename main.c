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

char *read_between(char *begin, char end, char *token, int *index)
{
  int i = *index;
  printf("BEGIN: %s\n", begin);
  printf("BEFORE \": %s\n", token);
  token[i] = *begin;
  begin++;
  i++;
  for (; *begin != end; begin++, i++)
  {
    token[i] = *begin;
  }
  token[i] = *begin;
  begin++;
  i++;
  *index = i;
  printf("AFTER \": %s\n", token);
  return begin;
}
Stack *tokenize(char *str, char separator)
{
  Stack *tokens = stack_create(100);
  char *c = str;
  char *token = str_alloc();
  int i = 0;
  for (; *c != '\0'; c++, i++)
  {
    if (*c == 34)
    { // c = \"
      c = read_between(c, 34, token, &i);
    }
    else if (*c == separator)
    {
      token[i] = '\0';
      i++;
      stack_push(tokens, token);
      i = -1;
      token = str_alloc();
    }
    else
    {
      token[i] = *c;
    }
    printf("%s\n", token);
  }
  token[i] = '\0';
  printf("%s\n", token);
  stack_push(tokens, token);
  return tokens;
}

int main(int argc, char const *argv[])
{
  history_test();
  map_test();
  pair_test();
  FILE *stream = stdin;
  Stack *tokens;
  while (1)
  {
    printf("    \\ > ");
    char *input = str_alloc();
    input[0] = 0;
    if (fscanf(stream, "%[^\n]s", input) == EOF)
      return NULL;
    fscanf(stream, "%*c");
    printf("-- %s --\n", input);
    if (input == NULL)
      break;
    if (strcmp("", input) == 0)
      continue;
    tokens = tokenize(input, 32);
    stack_print(tokens);
  }
  tokens = tokenize(stack_at(tokens, 1), '=');
  stack_print(tokens);
  return 0;
}

void test_command_externCommand()
{
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
}