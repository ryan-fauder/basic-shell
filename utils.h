#ifndef __UTILS_H__
#define __UTILS_H__

char * str_get(char *str);
char * str_alloc();
void str_free(char * str);
int str_length(char *str);
int space_counter(char *str);
int char_counter(char *str, char c);
int separator_counter(char *str, char* separator);
void clear_input(char *input);

#endif // __UTILS_H__