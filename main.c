#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sysexits.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctype.h>
#include "historico.h"
#include "map.h"
#include "stack.h"
#include "utils.h"

void test_env();
char *env_get(Map* map, char*key);
char *read_var(Map *map, char *begin, char *value, int *index);
char *checkForVariable(Map *map, char *str);

int main(int argc, char const *argv[])
{
  history_test();
  map_test();
  pair_test();
  test_env();
  return 0;
}



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

char *read_var(Map *map, char *begin, char *value, int *index){
  begin++;
  int i;
  char *var = str_alloc();
  for (i = 0; *begin != '\0'; begin++, i++)
  {
    if((tolower(*begin) < 'a' || tolower(*begin) > 'z') && (*begin < '0' || *begin > '9'))
      break;
    var[i] = *begin;
  }
  begin--;
  printf("VAR: %s\n", var);
  char *var_value = map_get(map, var);
  printf("VAR_VALUE: %s\n", var_value);
  i = *index;
  printf("BEFORE VALUE: %s\n", value);
  char *ptr = var_value;
  for (; *ptr != '\0'; ptr++, i++){
    value[i] = *ptr;
    printf("- %c", value[i-1]);
  }
  printf("AFTER VALUE: %s\n", value);
  *index = i;
  return begin;
}
char *checkForVariable(Map *map, char *str){
  char *c = str;
  char *value = str_alloc();
  int i = 0;
  for (; *c != '\0'; c++, i++)
  {
    if (*c == '$')
    { // c = \"
      c = read_var(map, c, value, &i);
    }
    else value[i] = *c;
    printf("%s\n", c);
  }
  printf("%s\n", value);
  return value;
}
char *env_get(Map* map, char*key){
  char * value;
  value = map_get(map, key);
  return checkForVariable(map, value);
}

void test_env(){
  char * value = NULL;
  Map *map = map_create(100);
  map_set(map, str_get("DTA"), str_get("/home/ryan"));
  map_set(map, str_get("DTA1"), str_get("/Doc/$DTA"));
  map_set(map, str_get("DTA2"), str_get("$DTA/$DTA1/>"));
	printf("RESULTADO: %s\n", env_get(map, str_get("DTA2")));
	printf("RESULTADO: %s\n", map_get(map, str_get("DTA2")));
}
void test_tokenize(){
  FILE *stream = stdin;
  Stack *tokens;
  while (1)
  {
    printf("    \\ > ");
    char *input = str_alloc();
    input[0] = 0;
    if (fscanf(stream, "%[^\n]s", input) == EOF) break;
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