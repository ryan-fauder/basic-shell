#ifndef __PAIR_H__
#define __PAIR_H__

/**
 * @struct Pair: Associa uma chave a um valor
 * 
 * @attr (char *) key: Chave do par
 * @attr (char *) value: Valor do par
 */
typedef struct
{
  char *key;
  char *value;
} Pair;

/**
 * @brief Cria um pair com chave e valor
 * 
 * @param key: char * 
 * @param value: char *
 * @return Pair* 
 */
Pair *pair_create(char *key, char *value);
/**
 * @brief Altera o valor de um pair
 * 
 * @param pair: Pair *
 * @param value: char *
 */
void pair_set(Pair *pair, char *value);
/**
 * @brief Obtem o valor de um pair com a chave
 * 
 * @param pair: Pair *
 * @param key: char *
 * @return char* 
 */
char *pair_get(Pair *pair, char *key);
/**
 * @brief Imprime um pair
 * 
 * @param pair: Pair *
 */
void pair_print(Pair *pair);
/**
 * @brief Libera um pair
 * 
 * @param pair: Pair *
 */
void pair_free(Pair *pair);
/**
 * @brief Testes unitarios para a estrutura de Pair
 * 
 */
void pair_test();

#endif //__PAIR_H__