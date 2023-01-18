#ifndef __PARSER_H__
#define __PARSER_H__
#include "env.h"

/**
 * @brief Escolhe o parser adequado para tratar o command informado
 * 
 * @param env: Env *
 * @param command: char *
 * @return char 
 */
char parser_controller(Env * env, char * command);

/**
 * @brief Trata o comando para limpar o terminal da shell
 * 
 */
void parser_limpa();

/**
 * @brief Trata o comando amb e escolhe a funcao adequada para o subtipo de amb
 * 
 * @param env: Env *
 * @param command: char *
 */
void parser_amb(Env *env, Reader * reader, char * command);

/**
 * @brief Trata o comando para imprimir ajuda
 * 
 */
void parser_ajuda();

/**
 * @brief Trata o comando para sair da shell
 * 
 * @return char 
 */
char parser_sair();

/**
 * @brief Trata o comando para executar um comando externo
 * 
 * @param env: Env *
 * @param tokens: Reader *
 */
void parser_externCommand(Env *env, Reader * tokens);

/**
 * @brief Trata o comando para alterar o diretorio da shell
 * 
 * @param env: Env *
 * @param tokens: Reader *
 */
void parser_changeDir(Env *env, Reader * tokens);

#endif //__PARSER_H__


