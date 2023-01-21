#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "utils.h"

Stack *stack_create(int capacity)
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));

  stack->size = 0;
  stack->top = -1;
  stack->capacity = capacity;
  stack->items = (char **)malloc(sizeof(char *) * capacity);
  return stack;
}

void stack_push(Stack *stack, char *value)
{
  if (stack->size >= stack->capacity)
  {
    printf("ERROR - PUSH NA PILHA: PILHA ATINGIU O LIMITE");
    return;
  }
  int index = stack->size;
  stack->items[index] = value;
  stack->top += 1;
  stack->size += 1;
}

char *stack_at(Stack *stack, int index)
{
  if (index < 0 || index > stack->top)
  {
    return NULL;
  }
  return stack->items[index];
}

char *stack_get(Stack *stack)
{
  if (stack->top < 0)
  {
    return NULL;
  }
  return stack->items[stack->top];
}

char *stack_pop(Stack *stack)
{
  if (stack->top < 0)
    return NULL;
  char *element = stack->items[stack->top];
  stack->top -= 1;
  stack->size -= 1;
  return element;
}

void stack_print(Stack *stack)
{
  for (int i = stack->top; i >= 0; i--)
  {
    printf("%d: %s\n", (i + 1), stack->items[i]);
  }
}

void stack_free(Stack *stack)
{
  for (int i = 0; i < stack->capacity; i++)
  {
    str_free(stack->items[i]);
    stack->items[i] = NULL;
  }
  free(stack->items);
  free(stack);
}

void stack_realloc(Stack *stack, int new_capacity)
{
  int currentCapacity = stack->capacity;

  // Cannot reduce a capacity of a stack.
  if (new_capacity <= currentCapacity)
    return;

  stack->capacity = new_capacity;
  char **temp = (char **)realloc(stack->items, sizeof(char *) * new_capacity);
  if (temp != NULL)
  {
    stack->items = temp;
  }
  else
  {
    printf("ERROR - NAO FOI POSSIVEL REALOCAR A PILHA");
  }
}