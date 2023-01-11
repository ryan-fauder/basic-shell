#include "historico.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char _history_filename[] = ".meushell.hst";

void setRecord(History * history, char record[]){
  // If last_record == record, so dont change the record
  if(strcmp(getRecord(history), record) == 0) return;

  history->_last_record = record;
  writeHistory(history);
  return;
}


char * getRecord(History * history){
  return history->_last_record;
}

History * createHistory(){
  History * history = (History *) malloc(sizeof(History));
  history->_last_record = (char *) malloc(2048);
  return history;
}

History * readHistory(){
  History * history = createHistory();
  FILE * f;
  f = fopen(_history_filename, "r+");

  if(f == NULL){
    printf("Falha");
    f = fopen(_history_filename, "w");
    return history;
  }
  fseek(f, 2048, SEEK_END);
  fscanf(f, "%s", history->_last_record);
  
  fclose(f);
  return history;
}
void writeHistory(History * history){
  FILE * f;

  f = fopen(_history_filename, "a");
  fprintf(f, "%s\n", history->_last_record);

  fclose(f);
}
void freeHistory(History * history){
  history->_last_record = NULL;
  free(history);
}
void printHistory();