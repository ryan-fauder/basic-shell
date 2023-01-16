#include<stdio.h>
#include<stdlib.h>
#include "env.h"
#include "map.h"
extern const int _ENV_INITIAL_CAPACITY;

Env *env_create(){
	Env *env = (Env *)malloc(sizeof(Env));
	env->varmap = map_create(_ENV_INITIAL_CAPACITY); 
	env->size = 0;
	env->capacity = _ENV_INITIAL_CAPACITY;
}

char *checkForVariable(char *str){
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


char *env_getVar(Env *env, char *key){
	char * value = NULL;
	value = map_get(env->varmap, key);





	return value;
}

void env_setVar(Env *env, char *key, char *value){
	if(env->size >= env->capacity){
		printf("Sem capacidade para alocar\n");
		map_realloc(env->varmap, (env->capacity)*2);
	}
	
	map_set(env->varmap, key, value);

	(env->size)++; 
}

Env *env_read(char *nameFile){
	Env *env = env_create();
	FILE *file = fopen(nameFile, "r+");

	if(file = NULL){
		file = fopen(nameFile, "w");
		fclose(file);
	}
	
	return env;

}

void env_free(Env *env){
	map_free(env->varmap);
	free(env);
}
