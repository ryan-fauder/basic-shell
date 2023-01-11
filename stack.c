#include "stack.h"
#include "utils.h"
#include <stdlib.h>

Stack * createStack(int capacity){
  Stack * stack = (Stack *) malloc(sizeof(Stack));
  
  stack->items = (char **) malloc(capacity);
  for (int i = 0; i < capacity; i++)
  {
    stack->items = (char *) malloc(sizeof(char) * 2048);
  }
  
}
void pushStack(Stack* stack, char * value){

}
char * getStack(Stack * stack){

}
void freeStack(Stack * stack){

}
void reallocStack(Stack * stack, int newCapacity){

}