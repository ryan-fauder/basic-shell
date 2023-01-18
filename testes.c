#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "commands.h"
#include "read.h"

char dta[32] = "/home/gabriel";

void imprimirErro(char *error) {
  printf("\nERROR : %s\n\n", error);
}

int main(int argc, char *argv[], char *envp[]) {
  char input[32];
  Reader *r = reader_create(10);
  while(1) {

    printf("gabriel@gabriel-dev: ~%s ", dta);
    scanf(" %[^\n]s", input);

    tokenize(input, ' ', r);
    reader_print(r);
    if(!r->length) continue;
    char *command = r->tokens[0];

    if(strcmp(command, "sair") == 0) {
      command_sair();
    } else if(strcmp(command, "limpa") == 0) {
      command_limpa();
    } else if(strcmp(command, "cd") == 0) {
      if(r->length == 1) {
        imprimirErro("O COMANDO PRECISA DE UM PARAMETRO");
        continue;
      }
      command_changeDir(r->tokens[1], dta);
    } else if(strcmp(command, "ajuda") == 0) {
      command_ajuda();
    } else {
      // se ls

      char **args = (char **)malloc(sizeof(char *) * 32);
      
      args[0] = command;
      args[1] = dta;

      if(r->length >= 2) {
        for (int i = 2; i < r->length+1; i++) {
          args[i] = r->tokens[i-1];
        }
      }
      
      args[r->length+1] = NULL;
      
      // printf("command input: %s\n", command);
      command_externCommand(command, args);
      // imprimirErro("COMMAND IS NOT FOUND");
    }
  }
  return 0;
}