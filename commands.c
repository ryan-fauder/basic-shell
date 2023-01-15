#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // fork
#include <sys/types.h>
#include <sys/wait.h>

void command_ajuda();
void command_amb_getAll();
void command_amb_getVar(char * nameVar);
void command_amb_setVar(char * nameVar, char * valueVar);
void command_externCommand(char * command);
void command_changeDir(char * path);
void command_limpa();
void command_print_history(/*History * history*/);
void command_sair();

int main(int argc, char *argv[], char *envp[]) {
  char input[32];

  while(1) {

    printf("Digite o comando : ");
    scanf(" %[^\n]s", input);

    if(strcmp(input, "sair") == 0) {
      command_sair();
    } else if(strcmp(input, "limpa") == 0) {
      printf("Limpando ...");
      command_limpa(argv, envp);
    } else {
      printf("Comando não encontrado");
    }
  }
  return 0;
}

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
  printf("Saindo ...");
  exit (1) ;
  return ;
}