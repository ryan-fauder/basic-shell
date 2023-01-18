#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern const int _COMMAND_SIZE;

char * remove_char(char *str, char charRemove) {
  int count = 0;
  while(str[count] != '\0') count++;
  
  char *newStr = (char*) malloc(sizeof(char)*count);
  int countNewStr = 0;
  for(int i =  0; i < count; i++) {
      if(str[i] != charRemove) {
          newStr[countNewStr] = str[i];
          countNewStr++;
      }
  }
  
  newStr[countNewStr] = '\0';
  
  return newStr;
}


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

int char_counter(char *str, char c) {
  int i = 0, count = 0;
  while(str[i] != '\0') {
    if(str[i] == c) count ++;
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