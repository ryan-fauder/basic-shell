#ifndef __HISTORICO_H__
#define __HISTORICO_H__

typedef struct {
  char * _last_record;
} History;

void setRecord(History * history, char record[]);
char * getRecord(History * history);
History * readHistory();
void writeHistory(History * history);
void freeHistory(History * history);

#endif //__HISTORICO_H__