#include <stdio.h>
#include <string.h>
#include "historico.h"
#include "stack.h"
#include "utils.h"

int main(int argc, char const *argv[])
{
  Stack * s = createStack(3);
  char * c = strAlloc();
  strcpy(c, "ELEMENT 1");
  pushStack(s, c );
  pushStack(s, "ELEMENT 2");
  pushStack(s, "ELEMENT 3");
  reallocStack(s, 5);
  popStack(s);
  pushStack(s, "ELEMENT 4");
  pushStack(s, "ELEMENT 5");
  printStack(s);
  
  freeStack(s);
  return 0;
  
}
