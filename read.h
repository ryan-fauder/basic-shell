#ifndef __READ_H__
#define __READ_H__

typedef struct str_tokens {
    char ** tokens;
    int length;
} reader;

void clear_input();
int space_counter(char *);

reader* createReader();
void pushReader(reader *r);
void popReader(reader *r);
void tokenize (char *, char, reader *);
char* read_line();

#endif //__READ_H__


