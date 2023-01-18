#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pair.h"
#include "utils.h"
Pair *pair_create(char *key, char *value)
{
  Pair *pair = (Pair *)malloc(sizeof(Pair));
  pair->key = key;
  pair->value = value;
  return pair;
}
void pair_set(Pair *pair, char *value){
  //str_free(pair->value);
  pair->value = value;
}
char *pair_get(Pair *pair, char *key)
{
  return (strcmp(pair->key, key) == 0) ? pair->value : NULL;
}
void pair_print(Pair *pair)
{
  printf("{ \"%s\": \"%s\" }", pair->key, pair->value);
}
void pair_free(Pair *pair)
{
  str_free(pair->key);
  str_free(pair->value);
}
void pair_test(){

  printf("TESTING - PAIR\n");
  Pair *p = pair_create(str_get("key1"), str_get("key2"));
  if(pair_get(p, "key2")) printf("Chave invalida");

  printf("%s\n", pair_get(p, "key1"));
  pair_print(p);
  printf("\n");
  pair_free(p);
}