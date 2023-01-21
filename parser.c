#include "parser.h"
#include "commands.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

char parser_controller(Env *env, char *command)
{
  Reader *reader = tokenize1(command, ' ');
  if (reader->length < 1)
    return 0;

  if (strcmp(reader->tokens[0], "cd") == 0)
  {
    parser_changeDir(env, reader);
  }
  else if (strcmp(reader->tokens[0], "amb") == 0)
  {
    if (reader->length > 2)
    {
      printf("COMANDO NAO ENCONTRADO: %s", command);
      reader_free(reader);
      return 1;
    }
    parser_amb(env, reader, command);
  }
  else if (strcmp(reader->tokens[0], "ajuda") == 0)
  {
    if (reader->length > 1)
    {
      printf("COMANDO NAO ENCONTRADO: %s", command);
      reader_free(reader);
      return 1;
    }
    parser_ajuda();
  }
  else if (strcmp(reader->tokens[0], "limpa") == 0)
  {
    if (reader->length > 1)
    {
      printf("COMANDO NAO ENCONTRADO: %s", command);
      reader_free(reader);
      return 1;
    }
    parser_limpa();
  }
  else if (strcmp(reader->tokens[0], "sair") == 0)
  {
    if (reader->length > 1)
    {
      printf("COMANDO NAO ENCONTRADO: %s", command);
      reader_free(reader);
      return 1;
    }
    return parser_sair();
  }
  else
  {
    parser_externCommand(env, reader);
  }
  reader_free(reader);
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
    return;
  }
  Reader *assign = tokenize1(reader->tokens[1], '=');
  if (assign->length == 1)
  {
    char *var_name = reader->tokens[1];
    if (var_name[0] != '$')
    {
      printf("ERROR: FORMATO DE VARIAVEL INVALIDO\n");
      reader_free(assign);
      return;
    }
    char *key = str_get(&var_name[1]);
    command_amb_getVar(env, key);
  }
  else if(assign->length == 2){
    char *var_name = str_get(assign->tokens[0]);
    char *var_value = str_get(assign->tokens[1]);
    if(var_value[0] == '\"'){
      var_value = remove_char(var_value, '\"');
    }
    command_amb_setVar(env, var_name, var_value);
  }
  else{
    printf("COMANDO NAO RECONHECIDO\n");
  }

  reader_free(assign);
  return;
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
  command_externCommand(env, reader->tokens[0], reader->tokens);
}
void parser_changeDir(Env *env, Reader *reader)
{
  if (reader->length < 2)
  {
    printf("COMANDO NAO RECONHECIDO");
    return;
  }
  char *current_dir = env_getVar(env, "DTA");
  command_changeDir(env, reader->tokens[1], current_dir);
}