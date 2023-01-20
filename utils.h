#ifndef __UTILS_H__
#define __UTILS_H__

/**
 * @brief Remove um caractere  
 * 
 *@param str:char *
 *@param charRemove: char
 * @return char *
 */
char * remove_char(char *str, char charRemove);
/**
 * @brief Retorna a string   
 * 
 *@param str:char *
 * @return char *
 */
char * str_get(char *str);
/**
 * @brief Aloca memória para a string 
 * 
 *
 * @return char *
 */
char * str_alloc();
/**
 * @brief Libera a string   
 * 
 *@param str:char *
 * 
 */
void str_free(char * str);
/**
 * @brief Conta o tamanho da string   
 * 
 *@param str:char *
 * @return int 
 */
int str_length(char *str);
/**
 * @brief Conta os espaços existentes   
 * 
 *@param str:char *
 * @return int 
 */
int space_counter(char *str);
/**
 * @brief Conta um caractere em específico    
 * 
 *@param str:char *
 *@param c: char
 * @return int 
 */
int char_counter(char *str, char c);
/**
 * @brief Contador de separações   
 * 
 *@param str:char *
 *@param separator:char *
 * @return int 
 */
int separator_counter(char *str, char* separator);
/**
 * @brief Limpa o input   
 * 
 *@param input:char *
 *  
 */
void clear_input(char *input);

#endif // __UTILS_H__
