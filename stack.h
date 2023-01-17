#ifndef __STACK_H__
#define __STACK_H__

/**
 * @struct Stack
 * 
 * @attr (char **) items: Vetor de strings;
 * @attr (int) top: Posicao do topo do items;
 * @attr (int) size: Tamanho do items;
 * @attr (int) capacity: Limite para o tamanho do items;
 * 
 */

typedef struct
{
  char **items;
  int top;
  int size;
  int capacity;
} Stack;

/**
 * @brief Cria uma pilha
 * 
 * @param capacity: int
 * @return Stack* 
 */
Stack *stack_create(int capacity);

/**
 * @brief Coloca um elemento no topo da pilha
 * 
 * @param stack: Stack *
 * @param value: char *
 */
void stack_push(Stack *stack, char *value);

/**
 * @brief Retorna o elemento no topo da pilha
 * 
 * @param stack: Stack *
 * @return char*
 */
char *stack_get(Stack *stack);

/**
 * @brief Retorna o elemento na posicao index
 * 
 * @param stack: Stack *
 * @param index: int
 * @return char* 
 */
char *stack_at(Stack *stack, int index);

/**
 * @brief Remove o elemento do topo da pilha
 * 
 * @param stack: Stack *
 * @return char* 
 */
char *stack_pop(Stack *stack);

/**
 * @brief Imprime uma stack
 * 
 * @param stack: Stack *
 */
void stack_print(Stack *stack);

/**
 * @brief Libera uma stack
 * 
 * @param stack: Stack *
 */
void stack_free(Stack *stack);

/**
 * @brief Realoca a capacidade da stack
 * 
 * @param stack: Stack *
 * @param new_capacity: int
 */
void stack_realloc(Stack *stack, int new_capacity);

#endif //__STACK_H__