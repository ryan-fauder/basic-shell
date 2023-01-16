#include <stdio.h>
#include <string.h>

#include "commands.h"
#include "read.h"

void imprimirErro(char *error) {
  printf("\nERROR : %s\n\n", error);
}

int main(int argc, char *argv[], char *envp[]) {
  char input[32];
  reader r;
  while(1) {

    printf("gabriel@gabriel-dev: ");
    scanf(" %[^\n]s", input);

    tokenize(input, ' ', &r);

    if(!r.length) continue;
    char *command = r.tokens[0];
    printf("Comando digitado : %s\n", command);

    if(strcmp(command, "sair") == 0) {
      command_sair();
    } else if(strcmp(command, "limpa") == 0) {
      command_limpa();
    } else if(strcmp(command, "cd") == 0) {
      if(r.length == 1) {
        imprimirErro(" O COMANDO PRECISA DE UM PARAMETRO");
        continue;
      }
      command_changeDir(r.tokens[1]);
    } else {
      imprimirErro("COMMAND IS NOT FOUND");
    }
  }
  return 0;
}