#include "parser.h"
#include <stdio.h>
#include <string.h>
char parser_controller(Env *env, char *command)
{
  char **tokens = tokenize(command);
  // if(tokens->size < 1) return 0;
  if (strcmp(tokens[0], "cd"))
  {
    parser_changeDir(env, tokens);
  }
  else if (strcmp(tokens[0], "amb"))
  {
    parser_amb(env, tokens, command);
  }
  else if (strcmp(tokens[0], "ajuda"))
  {
    if (tokens->size > 1)
    {
      printf("COMMAND NOT FOUND: %s", command);
    }
    parser_ajuda();
  }
  else if (strcmp(tokens[0], "limpa"))
  {
    if (tokens->size > 1)
    {
      printf("COMMAND NOT FOUND: %s", command);
    }
  }
  else if (strcmp(tokens[0], "sair"))
  {
    if (tokens->size > 1)
    {
      printf("COMMAND NOT FOUND: %s", command);
    }
    return parser_sair(env, tokens);
  }
  else
  {
    parser_externCommand(env, tokens);
  }
  return 0;
}
void parser_limpa()
{
  command_limpa();
}
void parser_amb(Env *env, char **tokens, char *command)
{
  if (tokens->size == 1)
  {
    command_amb_getAll(env);
  }
  else if (tokens->size == 2)
  {
    const *key = tokens[1];
    command_amb_get(env, key);
  }
  else
  {
    // Check about spaces into "".
    tokens = tokenize(command, "=");
    char **temp = tokenize(tokens[0], " ");
    tokens[0] = temp[1];
    if (tokens->size < 2)
    {
      printf("COMMAND NOT FOUND");
      return;
    }
    command_amb_set(env, tokens[0], tokens[1]);
  }
  return;
}
void parser_ajuda()
{
  command_ajuda();
}
char parser_sair()
{
  return NULL;
}
void parser_externCommand(Env *env, char **tokens)
{
  command_externCommand(env, tokens[0], tokens);
}
void parser_changeDir(Env *env, char **tokens)
{
  command_changeDir(env, tokens);
}