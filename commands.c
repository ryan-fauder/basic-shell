#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "commands.h"
#include "utils.h"
#include "read.h"

void command_ajuda() {
  char *help[] = {
    "limpa", "Limpar o terminal",
    "Ajuda", "Para pedir ajuda digite ajuda",
    "cd", "Comando para mudar de diretorio",
    "sair", "Finaliza a execucao",
  };

  for (int i = 0; i < 6; i+=2){
    printf("- %s : %s\n", help[i], help[i+1]);
  }
  
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
void command_externCommand(char * command, char **argv) {
  int pid = fork ();
  if(pid == 0) {
    // processo filho
    int a = execvp(command, argv);
    printf("%d\n", a);
    perror("Erro: ");
  } else {
    // processo pai
    wait(0) ;
  }
  return ;
}


void command_changeDir(char * path, char *dta) {
  int strLength = str_length(path);
  if(strLength == 0) return ;

  // tokenizar entrada
  // printf("tokenize input\n");
  Reader *inputReader = reader_create(10);
  tokenize(path, '/', inputReader);
  // reader_print(inputReader);

  //tokenizar path atual
  // printf("tokenize dta\n");
  Reader * dtaReader = reader_create(10);
  tokenize(dta, '/', dtaReader);
  // reader_print(dtaReader);

  for(int i = 0; i < inputReader->length; i++) {
    if(strcmp(inputReader->tokens[i], "..") == 0) {
      reader_pop(dtaReader);
    } else {
      reader_push(dtaReader, inputReader->tokens[i]);
    }
  }

  char *alterPath = reader_join(dtaReader, "/");
  // printf("Path Resultado : %s\n", alterPath);
  strcpy(dta, alterPath);
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