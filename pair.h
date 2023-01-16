#ifndef __PAIR_H__
#define __PAIR_H__
typedef struct
{
  char *key;
  char *value;
} Pair;

Pair *pair_create(char *key, char *value);
void pair_set(Pair *pair, char *value);
char *pair_get(Pair *pair, char *key);
void pair_print(Pair *pair);
void pair_free(Pair *pair);
void pair_test();

#endif //__PAIR_H__