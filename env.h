#ifndef __ENV_H__
#define __ENV_H__
#include "map.h"

typedef struct{
	Map *varmap;
	int size;
	int capacity; 
} Env;
/**
 * @brief cria um env 
 * 
 * @return Env* 
 */
Env *env_create();

/**
 * @brief Pega a varíavel de dentro do mapa
 * 
 * @param env: Env *
 * @param key: char * 
 * @return char* 
 */
char *env_getVar(Env *env, char *key);
/**
 * @brief Vai atribuir o valor na variável conseguida no mapa
 * 
 * @param env: Env *
 * @param key: char *
 * @param value: char *
 */
void env_setVar(Env *env, char *key, char *value);
/**
 * @brief vai ler o arquivo escrito
 * 
 * @param nameFile: char *
 * @return Env* 
 */
Env *env_read(char *nameFile);
/**
 * @brief vai escrever o arquivo e atribuir seus valores 
 * 
 * @param env: env *
 * @param nameFile: char *
 */
void env_write(Env *env, char *nameFile);
/**
 * @brief vai liberar o arquivo 
 * 
 * @param env: env *
 */
void env_free(Env *env);
/**
 * @brief local de testes da função 
 * 
 */
void env_test();
/**
 * @brief Substitute variables from a string
 * 
 * @param env: Env *
 * @param str: char *
 * @return char* 
 */
char *env_resolveVar(Env *env, char *str);
#endif
