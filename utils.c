#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
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

int space_counter(char *str) {
  int i = 0, count = 0;
  while(str[i] != '\0') {
    if(str[i] == ' ') count ++;
    i++;
  }
  return count;
}

int separator_counter(char *str, char* separator) {
  int count = 0;
  char *pt;

  pt = strtok (str, separator);
  if(pt != NULL) count++;

  while(pt != NULL) {
    pt = strtok (NULL, separator);
    if(pt == NULL) break;
    
    count++;
  }
  
  return count;
}

void clear_input(char *input) {
  int i = 0;
  while(i < _COMMAND_SIZE) {
    input[i] = '\0';
    i++;
  }
}