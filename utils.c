#include "utils.h"
#include <stdlib.h>

extern const int _COMMAND_SIZE;
char * str_alloc(){
  return (char *) malloc(_COMMAND_SIZE);
}
void str_free(char * str){
  free(str);
}