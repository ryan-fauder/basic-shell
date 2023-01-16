#include "utils.h"
#include <stdlib.h>
#include <string.h>
extern const int _COMMAND_SIZE;

char * str_get(char *str){
  char *buffer = (char *) malloc(_COMMAND_SIZE);
  strcpy(buffer, str);
  return buffer;
}
char * str_alloc(){
  return (char *) malloc(_COMMAND_SIZE);
}
void str_free(char * str){
  free(str);
}

int str_length(char *str) {
  int i = 0;
  while(str[i] != '\0') i++;
  return i;
}