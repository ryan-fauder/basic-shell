#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "map.h"
#include "pair.h"
#include "utils.h"
Map *map_create(int capacity)
{
  Map *map = (Map *)malloc(sizeof(Map));

  map->size = 0;
  map->capacity = capacity;
  map->pairs = (Pair **)malloc(sizeof(Pair *) * capacity);
  return map;
}
void map_set(Map *map, char *key, char *value)
{
  if (map->size >= map->capacity)
  {
    printf("ERROR - SET INTO MAP: MAP AT CAPACITY");
    return;
  }

  int index = map->size;
  Pair *current_pair = map_pair_get(map, key);
  Pair *pair = pair_create(key, value);

  if(current_pair == NULL){
    map->pairs[index] = pair;
    map->size += 1;
  }
  else{
    pair_set(current_pair, value);
  }
}

Pair *map_pair_get(Map *map, char *key){
  Pair *pair = NULL;
  char *value = NULL;
  for (int i = 0; i < map->size; i++)
  {
    pair = map->pairs[i];
    value = pair_get(pair, key);
    if (value != NULL)
      break;
    pair = NULL;
  }
  return pair;
}

char *map_get(Map *map, char *key)
{
  Pair *pair = NULL;
  char *value = NULL;
  for (int i = 0; i < map->size; i++)
  {
    pair = map->pairs[i];
    value = pair_get(pair, key);
    if (value != NULL)
      break;
  }
  return value;
}
void map_print(Map *map)
{
  for (int i = 0; i < map->size; i++)
  {
    pair_print(map->pairs[i]);
    printf("\n");
  }
}
void map_free(Map *map)
{
  for (int i = 0; i < map->size; i++)
  {
    pair_free(map->pairs[i]);
  }
  free(map->pairs);
  free(map);
}
void map_realloc(Map *map, int new_capacity)
{
  int currentCapacity = map->capacity;

  // Cannot reduce a capacity of a map.
  if (new_capacity <= currentCapacity)
    return;

  map->capacity = new_capacity;
  Pair **temp = (Pair **)realloc(map->pairs, sizeof(Pair *) * new_capacity);
  if (temp != NULL)
    map->pairs = temp;
  else
    printf("ERROR - UNABLE TO REALLOCATE MEMORY FOR MAP");
}
void map_test(){
  printf("TESTING - MAP\n");
  Map * map = map_create(100);
  map_set(map, str_get("CHAVE 1"), str_get("VALOR 1"));
  map_set(map, str_get("CHAVE 2"), str_get("VALOR 2"));
  map_set(map, str_get("CHAVE 3"), str_get("VALOR 3"));
  map_set(map, str_get("CHAVE 4"), str_get("VALOR 4"));
  map_print(map);
  printf("\n");
  printf("%s\n", map_get(map, "CHAVE 4"));
  map_free(map);
}