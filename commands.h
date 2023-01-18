#ifndef __COMMANDS_H__
#define __COMMANDS_H__

void command_ajuda();
void command_amb_getAll(Env *env);
void command_amb_getVar(Env *env, char *nameVar);
void command_amb_setVar(Env *env, char *nameVar, char *valueVar);
void command_externCommand(char *command, char **argv);
void command_changeDir(char *path, char *dta);
void command_limpa();
void command_print_history();
void command_sair();

#endif // __COMMANDS_H__