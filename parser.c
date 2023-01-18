#include "parser.h"
#include "read.h"
#include <stdio.h>
#include <string.h>
char parser_controller(Env *env, char *command)
{
  Reader *reader = tokenize1(command, ' ');
  if(reader->length < 1) return 0;

  if (strcmp(reader->tokens[0], "cd"))
  {
    parser_changeDir(env, reader->tokens);
  }
  else if (strcmp(reader->tokens[0], "amb"))
  {
    parser_amb(env, reader->tokens, command);
  }
  else if (strcmp(reader->tokens[0], "ajuda"))
  {
    if (reader->length > 1)
    {
      printf("COMMAND NOT FOUND: %s", command);
    }
    parser_ajuda();
  }
  else if (strcmp(reader->tokens[0], "limpa"))
  {
    if (reader->length > 1)
    {
      printf("COMMAND NOT FOUND: %s", command);
    }
  }
  else if (strcmp(reader->tokens[0], "sair"))
  {
    if (reader->length > 1)
    {
      printf("COMMAND NOT FOUND: %s", command);
    }
    return parser_sair(env, reader->tokens);
  }
  else
  {
    parser_externCommand(env, reader->tokens);
  }
  return 0;
}
void parser_limpa()
{
  command_limpa();
}
void parser_amb(Env *env, Reader *reader, char *command)
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
    parser_amb_set(env, tokens);
  }
  return;
}
void command_amb_set(Env *env, Reader *reader){
    // Check about spaces into "".
    const char**attrb = tokenize1(tokens[1], "=");
    
    tokens = tokenize1(command, "=");
    char **temp = tokenize1(tokens[0], " ");
    tokens[0] = temp[1];
    if (tokens->size < 2)
    {
      printf("COMMAND NOT FOUND");
      return;
    }
    command_amb_set(env, tokens[0], tokens[1]);
}
void parser_ajuda()
{
  command_ajuda();
}
char parser_sair()
{
  return NULL;
}
void parser_externCommand(Env *env, Reader *reader)
{
  command_externCommand(env, reader->tokens[0], reader->tokens);
}
void parser_changeDir(Env *env, Reader *reader)
{
  command_changeDir(env, reader->tokens[1]);
}