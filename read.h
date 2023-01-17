#ifndef __READ_H__
#define __READ_H__

typedef struct str_tokens
{
    char **tokens;
    int length;
    int max_length;
} reader;

void clear_input();
int space_counter(char *);
reader* createReader(int initial_size);
void pushReader(reader *r, char *str);
void popReader(reader *r);
void tokenize (char *, char, reader *);
char* read_line(char *input);
void freeReader(reader *r);
void print_reader(reader *r);
char* concatTokens(reader *r);

#endif //__READ_H__
