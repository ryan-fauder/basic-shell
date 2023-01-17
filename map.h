#ifndef __MAP_H__
#define __MAP_H__
#include "pair.h"

/**
 * @struct Map
 * 
 * @attr (Pair **) pairs: Vetor com pairs
 * @attr (int) size: Tamanho do pairs;
 * @attr (int) capacity: Limite para o tamanho do pairs
 */

typedef struct
{
  Pair **pairs;
  int size;
  int capacity;
} Map;

/**
 * @brief Cria um map
 *
 * @param capacity: int
 * @return Map*
 */
Map *map_create(int capacity);

/**
 * @brief Define um par e armazena no map
 *
 * @param map: Map *
 * @param key: char *
 * @param value: char *
 */
void map_set(Map *map, char *key, char *value);

/**
 * @brief Dado uma chave, retorna o par associado
 *
 * @param map: Map *
 * @param key: char *
 * @return Pair*
 */
Pair *map_pair_get(Map *map, char *key);

/**
 * @brief Dada uma chave, retorna o valor associado
 *
 * @param map: Map *
 * @param key: Char *
 * @return char*
 */
char *map_get(Map *map, char *key);
/**
 * @brief Imprime um map
 *
 * @param map: Map *
 */
void map_print(Map *map);
/**
 * @brief Libera um map
 *
 * @param map: Map *
 */
void map_free(Map *map);

/**
 * @brief Realoca a capacidade do map
 *
 * @param map: Map *
 * @param new_capacity: int
 */
void map_realloc(Map *map, int new_capacity);

/**
 * @brief Teste unitario para a estrutura map
 *
 */
void map_test();

#endif //__MAP_H__