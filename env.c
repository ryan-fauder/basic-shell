#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "env.h"
#include "map.h"
#include "utils.h"
#include "read.h"

extern const int _ENV_INITIAL_CAPACITY;
char *env_placeVar(Env *env, char *itr_str, char *value, int *value_size);

Env *env_create()
{
  Env *env = (Env *)malloc(sizeof(Env));
  env->varmap = map_create(_ENV_INITIAL_CAPACITY);
  env->size = 0;
  env->capacity = _ENV_INITIAL_CAPACITY;
}

char *env_getVar(Env *env, char *key)
{
  char *value = NULL;
  if(key == NULL){
    printf("ERROR - GET A VALUE FROM ENV WITH A NULL KEY");
    return NULL;
  }
  value = map_get(env->varmap, key);
  if(value == NULL){
    printf("ERROR - GOT A NULL VALUE FROM ENV");
    return NULL;
  }
  return env_resolveVar(env, value);
  // return value;
}

void env_setVar(Env *env, char *key, char *value)
{
  if (env->size >= env->capacity)
  {
    printf("Sem capacidade para alocar\n");
    map_realloc(env->varmap, (env->capacity) * 2);
    env->capacity  = env->capacity * 2;
  }
  map_set(env->varmap, key, value);
  
  env->size = env->varmap->size;
}

void env_write(Env *env, char *nameFile)
{
  FILE *stream = fopen(nameFile, "w+");
  if (stream == NULL)
  {
    printf("Error - Cannot write a env");
    fclose(stream);
  }
  int i;
  char *key;
  char *value;
  for (i = 0; i < env->size; i++)
  {
    key = env->varmap->pairs[i]->key;
    value = env->varmap->pairs[i]->value;
    fprintf(stream, "%s=%s\n", key, value);
  }
  fclose(stream);
}

Env *env_read(char *nameFile)
{
  Env *env = env_create();
  FILE *stream = fopen(nameFile, "r+");

  if (stream == NULL)
  {
    stream = fopen(nameFile, "w");
    fclose(stream);
    return env;
  }
  char *buffer = str_alloc();
  while (fscanf(stream, "%[^\n]", buffer) == 1)
  {
    fscanf(stream, "%*c");

    Reader *reader = tokenize1(buffer, '=');
    char *key = reader->tokens[0];
    char *value = reader->tokens[1];
    env_setVar(env, key, value);
  }

  fclose(stream);
  return env;
}

void env_free(Env *env)
{
  map_free(env->varmap);
  free(env);
}

void env_test()
{
  Env *env = env_create();
  env_setVar(env, str_get("DTA"), str_get("/home/ryan"));
  env_setVar(env, str_get("DTA1"), str_get("/Doc/$DTA"));
  env_setVar(env, str_get("DTA2"), str_get("$DTA/$DTA1//$DTA1$DTA1 />"));
  env_setVar(env, str_get("DTA3"), str_get("/Downloads"));
  printf("RESULTADO DTA3: %s\n", env_getVar(env, str_get("DTA3")));
  printf("RESULTADO DTA2: %s\n", env_getVar(env, str_get("DTA2")));
  printf("RESULTADO DTA1: %s\n", env_getVar(env, str_get("DTA1")));
  printf("RESULTADO DTA: %s\n", env_getVar(env, str_get("DTA")));
  
  env_write(env, "Teste1.txt");
  env = env_read("Teste1.txt");
}

char *env_placeVar(Env *env, char *itr_str, char *value, int *value_size)
{
  char *var = str_alloc();
  int var_size = 0;
  for (var_size = 0; *itr_str != '\0'; itr_str++, var_size++)
  {
    if ((tolower(*itr_str) < 'a' || tolower(*itr_str) > 'z') && (*itr_str < '0' || *itr_str > '9'))
      break;
    var[var_size] = *itr_str;
  }
  itr_str--;

  char *var_value = env_getVar(env, var);
  char *ptr = var_value;
  int temp_size = *value_size;

  for (; *ptr != '\0'; ptr++, temp_size++)
  {
    value[temp_size] = *ptr;
  }
  *value_size = temp_size;

  return itr_str;
}

char *env_resolveVar(Env *env, char *str)
{
  char *itr_str = str;
  char *value = str_alloc();
  int value_size = 0;
  for (; *itr_str != '\0'; itr_str++)
  {
    if (*itr_str == '$')
    {
      itr_str++;
      itr_str = env_placeVar(env, itr_str, value, &value_size);
    }
    else
    {
      value[value_size] = *itr_str;
      value_size++;
    }
    /*
    if(value_size >= 31){
      printf("COMMAND CAPACITY AT LIMIT");
      break;
    }
    */
  }

  value[value_size] = '\0';
  value_size++;

  return value;
}
