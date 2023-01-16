
typedef struct str_tokens {
    char ** tokens;
    int length;
} reader;

void clear_input();
int space_counter(char *);
char** tokenize (char *, reader *);
char* read_line();