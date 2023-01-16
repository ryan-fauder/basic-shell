#ifndef __READ_H__
#define __READ_H__

typedef struct str_tokens
{
    char **tokens;
    int length;
    int capacity;
} Reader;

void clear_input();
int space_counter(char *);

Reader *reader_create();
void reader_push(Reader *reader);
void reader_pop(Reader *reader);
void reader_realloc(Reader *reader, int new_capacity);
char *reader_toString(Reader *reader);
void tokenize(Reader *reader, char *string, char separator);
char *read_line();

#endif //__READ_H__
