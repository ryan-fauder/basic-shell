
typedef struct str_tokens {
    char ** tokens;
    int length;
} tokens;

void clear_input();
int string_length(char *);
int space_counter(char *);
char** tokenize (char *, tokens *);
char* read_line();