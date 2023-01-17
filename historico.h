#ifndef __HISTORICO_H__
#define __HISTORICO_H__
#include "stack.h"
/**
 * @struct History
 * 
 * @attr (Stack *) stack: Estrutura da pilha
 * @attr (int) size: Tamanho da stack;
 * @attr (int) capacity: Limite para o tamanho da stack
 */
typedef struct
{
  Stack *stack;
  int size;
  int capacity;
} History;

/**
 * @brief Cria um history
 * 
 * @return History* 
 */
History *history_create();

/**
 * @brief Armazena um registro em um history
 * 
 * @param history: History *
 * @param record: char *
 */
void history_setRecord(History *history, char *record);

/**
 * @brief Obtem um registro em um history
 * 
 * @param history: History * 
 * @return char* 
 */
char *history_getRecord(History *history);

/**
 * @brief Realiza a leitura de uma estrutura History em um arquivo
 * 
 * @return History* 
 */
History *history_read();

/**
 * @brief Escreve um history em um arquivo
 * 
 * @param history: History * 
 */
void history_write(History *history);

/**
 * @brief Imprime um history
 * 
 * @param history: History * 
 */
void history_print(History *history);

/**
 * @brief Libera um history
 * 
 * @param history: History * 
 */
void history_free(History *history);

/**
 * @brief Realoca um history
 * 
 * @param history: History * 
 * @param new_capacity: int
 */
void history_realloc(History *history, int new_capacity);

/**
 * @brief Testes unitarios para a estrutura History
 * 
 */
void history_test();

#endif //__HISTORICO_H__