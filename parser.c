#include "parser.h"
#include "commands.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

char parser_controller(Env *env, char *command)
{
  Reader *reader = tokenize1(command, ' ');

  if(reader->length < 1) return 0;

  if (strcmp(reader->tokens[0], "cd")== 0)
  {
    parser_changeDir(env, reader);
  }
  else if (strcmp(reader->tokens[0], "amb") == 0)
  {
    parser_amb(env, reader, command);
  }
  else if (strcmp(reader->tokens[0], "ajuda") == 0)
  {
    if (reader->length > 1)
    {
      printf("COMMAND NOT FOUND: %s", command);
    }
    parser_ajuda();
  }
  else if (strcmp(reader->tokens[0], "limpa") == 0)
  {
    if (reader->length > 1)
    {
      printf("COMMAND NOT FOUND: %s", command);
    }
    parser_limpa();
  }
  else if (strcmp(reader->tokens[0], "sair") == 0)
  {
    if (reader->length > 1)
    {
      printf("COMMAND NOT FOUND: %s", command);
    }
    return parser_sair();
  }
  else
  {
    parser_externCommand(env, reader);
  }
  return 1;
}
void parser_limpa()
{
  command_limpa();
}
void parser_amb(Env *env, Reader *reader, char *command)
{
  if (reader->length == 1)
  {
    command_amb_getAll(env);
  }
  else if (reader->length == 2)
  {
    char *key = reader->tokens[1];
    command_amb_getVar(env, key);
  }
  else
  {
    parser_amb_set(env, reader, command);
  }
  return;
}
void parser_amb_set(Env *env, Reader *reader, char * command){
    // Check about spaces into "".
    Reader * attrb = tokenize1(reader->tokens[1], '=');
    char * var_name = str_get(attrb->tokens[0]);
    char * var_value = str_get(attrb->tokens[1]);
    if (reader->length < 2)
    {
      printf("COMMAND NOT FOUND");
      return;
    }
    command_amb_setVar(env, var_name, var_value);
}
void parser_ajuda()
{
  command_ajuda();
}
char parser_sair()
{
  return 0;
}
void parser_externCommand(Env *env, Reader *reader)
{
  command_externCommand(reader->tokens[0], reader->tokens);
}
void parser_changeDir(Env *env, Reader *reader)
{
  char * current_dir = env_getVar(env, "DTA");
  reader_print(reader);
  printf("%s\n", reader->tokens[1]);
  printf("%s\n", current_dir);
  command_changeDir(env, reader->tokens[1], current_dir);
}