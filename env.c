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
