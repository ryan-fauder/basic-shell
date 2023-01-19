#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "env.h"
/**
*@brief Cria um painel com as opções possíveis de comandos
*
*/
void command_ajuda();
/**
*@brief Mostrar todas as váriáveis existentes  
*
*@param env: Env*
*/
void command_amb_getAll(Env *env);
/**
*@brief Vai pegar a variável especificada dentro do pair 
*
*@paran env: Env*
*@param nameVar: char*
*/
void command_amb_getVar(Env *env, char *nameVar);
/**
*@brief Vai atribuir o valor a variável adicionada
*
*@param env: Env*
*@param nameVar: char*
*@param valueVar: char*
*/

void command_amb_setVar(Env *env, char *nameVar, char *valueVar);
void command_externCommand(Env *env, char *command, char **argv);
void command_changeDir(Env * env, char *path, char *dta);
void command_limpa();
void command_print_history();
void command_sair();

#endif // __COMMANDS_H__
