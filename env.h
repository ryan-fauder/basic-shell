#ifndef __ENV_H__
#define __ENV_H__
#include "map.h"

typedef struct{
	Map *varmap;
	int size;
	int capacity; 
} Env;

Env *env_create();
char *env_getVar(Env *env, char *key);
void env_setVar(Env *env, char *key, char *value);
Env *env_read(char *nameFile);
void env_free(Env *env);
void env_test();

#endif
