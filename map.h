#ifndef __MAP_H__
#define __MAP_H__
#include "pair.h"
typedef struct
{
  Pair **pairs;
  int size;
  int capacity;
} Map;

Map *map_create(int capacity);
void map_set(Map *map, char *key, char *value);
char *map_get(Map *map, char *key);
void map_print(Map *map);
void map_free(Map *map);
void map_realloc(Map *map, int newCapacity);
void map_test();
#endif //__MAP_H__