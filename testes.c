#include <stdio.h>
#include <string.h>

#include "commands.h"

int main(int argc, char *argv[], char *envp[]) {
  char input[32];

  while(1) {

    printf("gabriel@gabriel-dev: ");
    scanf(" %[^\n]s", input);

    if(strcmp(input, "sair") == 0) {
      command_sair();
    } else if(strcmp(input, "limpa") == 0) {
      command_limpa();
    } else if(input[0] == '.') {
      command_changeDir(input);
    } else {
      printf("Comando não encontrado\n");
    }
  }
  return 0;
}