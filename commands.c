#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "commands.h"
#include "utils.h"

void command_ajuda() {
  return ;
}
void command_amb_getAll() {
  return ;
}
void command_amb_getVar(char * nameVar) {
  return ;
}
void command_amb_setVar(char * nameVar, char * valueVar) {
  return ;
}
void command_externCommand(char * command) {
  return ;
}
void command_changeDir(char * path) {
  char *currentDir = "/home/gabriel/Downloads";
  int strLength = str_length(path);
  int count = 0;
  if(strLength == 0) return ;
  return ;
}
void command_limpa() {
  int pid = fork ();
  char **argv = NULL;
  if(pid == 0) {
    // processo filho
    execvp("/bin/clear", argv);
    perror("Erro: ") ;
  } else {
    // processo pai
    wait(0) ;
  }
  return ;
}
void command_print_history(/*History * history*/) {
  return ;
}
void command_sair() {
  printf("Saindo ...\n");
  exit (1) ;
  return ;
}