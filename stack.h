#ifndef __STACK_H__
#define __STACK_H__
typedef struct
{
  char **items;
  int top;
  int size;
  int capacity;
} Stack;

Stack *stack_create(int capacity);
void stack_push(Stack *stack, char *value);
char *stack_get(Stack *stack);
char *stack_at(Stack *stack, int index);
char *stack_pop(Stack *stack);
void stack_print(Stack *stack);
void stack_free(Stack *stack);
void stack_realloc(Stack *stack, int new_capacity);

#endif //__STACK_H__