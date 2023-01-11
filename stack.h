#ifndef __STACK_H__
#define __STACK_H__
typedef struct {
  char ** items;
  int top;
  int size;
  int capacity;
} Stack;

Stack * createStack(int capacity);
void pushStack(Stack* stack, char * value);
char * getStack(Stack * stack);
void freeStack(Stack * stack);
void reallocStack(Stack * stack, int newCapacity);


#endif //__STACK_H__