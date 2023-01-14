#include<stdio.h>
#include<stdlib.h>
#include "env.h"
#include "map.h"

Env *env_create(){
	Env *env = (Env *)malloc(sizeof(Env));
	env->VARMAP = map_create(_HISTORY_INITIAL_CAPACITY); 
	env->size = 0;
	env->capacity = map.capacity;
}

char *env_getVar(Env *env, char *key){
	char * maps = NULL;
	char * value = NULL;

	for(i = 0; i < env->size; i++){
		value = map_get(VARMAP[i], key);
	}
	if(value == NULL){
		printf("variable not found\n");
		return " ";
	}

	return value;
}

void env_setVar(Env *env, char *key, char *value){
	if(env->size >= env->capacity){
		printf("Sem capacidade para alocar\n");
		map_realloc(map, (env->capacity)*2);
	}
	
	int i = env->size;
	Env *envs = map_create(env->capacity); 
	
	env->VARMAP[i] = envs;
	(env->size)++; 
}

Env *env_read(char *nameFile){
	Env *env = env_create();
	FILE *file = fopen(arquivoEnv, "r+")

	if(file = NULL){
		file = fopen(arquivoEnv, "w");
		fclose(file);
	}
	
	return env;

}

void env_free(Env *env){
	map_free(env->VARMAP);
	free(env);
}


