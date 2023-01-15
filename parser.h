#ifndef __PARSER_H__
#define __PARSER_H__
#include "env.h"
char parser_controller(Env * env, char * command);
void parser_limpa();
void parser_amb(Env *env, char * command);
void parser_ajuda();
char parser_sair();
void parser_externCommand(Env *env, char ** tokens);
void parser_changeDir(Env *env, char ** tokens);

#endif //__PARSER_H__


