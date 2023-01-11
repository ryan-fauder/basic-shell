#include "utils.h"
#include <stdlib.h>

const int _COMMAND_SIZE = 2048;
char * strAlloc(){
  return (char *) malloc(_COMMAND_SIZE);
}
void strFree(char * str){
  free(str);
}