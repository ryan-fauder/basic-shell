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
  for (int i = 0; i < capacity; i++)
  {
    stack->items[i] = (char *)strAlloc();
  }
  return stack;
}

void stack_push(Stack *stack, char *value)
{
  if (stack->size >= stack->capacity)
  {
    printf("ERROR - PUSH TO STACK: STACK AT CAPACITY");
    return;
  }
  int index = stack->size;
  strcpy(stack->items[index], value);
  stack->top += 1;
  stack->size += 1;
}

char *stack_at(Stack *stack, int index)
{
  if (stack->top < 0)
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
    strFree(stack->items[i]);
    stack->items[i] = NULL;
  }
  free(stack->items);
  free(stack);
}

void stack_realloc(Stack *stack, int newCapacity)
{
  int currentCapacity = stack->capacity;

  // Cannot reduce a capacity of a stack.
  if (newCapacity <= currentCapacity)
    return;

  stack->capacity = newCapacity;
  char **temp = (char **)realloc(stack->items, sizeof(char *) * newCapacity);
  if (temp != NULL)
  {
    stack->items = temp;
    for (int i = currentCapacity; i < newCapacity; i++)
    {
      stack->items[i] = (char *)strAlloc();
    }
  }
  else
  {
    printf("UNABLE TO REALLOCATE MEMORY");
  }
}