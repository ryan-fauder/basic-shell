#ifndef __READ_H__
#define __READ_H__
#include <stdio.h>
typedef struct str_tokens
{
    char **tokens;
    int length;
    int max_length;
} Reader;

Reader* reader_create(int initial_size);
void reader_push(Reader *r, char *str);
void reader_pop(Reader *r);
void tokenize(char *, char, Reader *);
Reader *tokenize1(char *str, char separator);
char *read_between(char *begin, char end, char *token, int *index);
char* read_line(FILE * stream);
void reader_free(Reader *r);
void reader_print(Reader *r);
char* reader_join(Reader *r, char * separator);

#endif //__READ_H__
