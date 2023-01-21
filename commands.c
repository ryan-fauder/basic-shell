#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "commands.h"
#include "utils.h"
#include "read.h"
#include "pair.h"

#include <dirent.h>
#include <errno.h>

void command_ajuda() {
  printf("\n");
  printf("==================== MANUAL DA SHELL ====================\n\n");
  char *help[] = {
    "limpa", "Limpar o terminal",
    "Ajuda", "Para pedir ajuda digite ajuda",
    "cd", "Comando para mudar de diretorio",
    "sair", "Finaliza a execucao",
    "Variaveis de Ambiente", "Para definir uma variavel de ambiente, basta digitar amb NOME_VARIAVEL=\"CONTEUDO\"",
    "Exibir Variaveis de Ambiente", "Para exibir as variaveis de ambiente disponiveis, basta digitar amb $NOME_VARIAVEL",
    "Listar Variaveis de Ambiente", "Para exibir todas as variaveis de ambiente entre com o comando amb",
    "Comandos Externos", "A shell tambem aceita comandos externos do linux"
  };

  for (int i = 0; i < 16; i+=2){
    printf("- %s : %s\n", help[i], help[i+1]);
    printf("\n");
  }
  
  return ;
}
void command_amb_getAll(Env * env) {
  Pair * pair;
  printf("Variaveis de ambiente: \n");
  for (int i = 0; i < env->size; i++)
  {
    pair = env->varmap->pairs[i];
    printf("- %s=%s\n",pair->key, env_getVar(env, pair->key));
  }
}
void command_amb_getVar(Env * env, char * nameVar) {
  printf("- %s=%s\n", nameVar, env_getVar(env, nameVar));
}
void command_amb_setVar(Env * env, char * nameVar, char * valueVar) {
  env_setVar(env, nameVar, valueVar);
  printf("Variavel adicionada:\n %s=%s\n", nameVar, env_getVar(env, nameVar));
}
void command_externCommand(Env * env, char * command, char **argv) {
  int pid = fork();
  int status;
  if(pid == 0) {
    // processo filho
    char * current_dir = env_getVar(env, "DTA");
    int error_dir = chdir(current_dir);
    if(error_dir == -1){  
      printf("ERROR: SHELL NAO PODE EXECUTAR O COMANDO NO DIRETORIO\n");
      exit(0);
    }
    int error = execvp(command, argv);
    if(error == -1){  
      printf("COMANDO NAO RECONHECIDO\n");
      exit(0);
    }
  } else {
    // processo pai
    waitpid(pid, &status, 0);
  }
  return ;
}
void command_changeDir(Env * env, char * path, char *dta) {
  int strLength = str_length(path);
  if(strLength == 0) return ;

  // tokenizar entrada
  Reader *inputReader = tokenize1(path, '/');

  //tokenizar path atual
  Reader * dtaReader = tokenize1(dta, '/');
  
  for(int i = 0; i < inputReader->length; i++) {
    if(strcmp(inputReader->tokens[i], "..") == 0) {
      reader_pop(dtaReader);
    } 
    else if(strcmp(inputReader->tokens[i], ".") == 0) {
      continue;
    }
    else {
      reader_push(dtaReader, inputReader->tokens[i]);
    }
  }


  char *alterPath = reader_join(dtaReader, "/");
  int flag = command_validate_dir(alterPath);
  if(flag != 1) {
    if(flag == 0) {
      printf("ERROR: DIRETORIO NAO EXISTE\n");
    } else {
      printf("ERROR: DIRETORIO DESCONHECIDO\n");
    }
    return ;
  }
  env_setVar(env, str_get("DTA"), alterPath);
  return ;
}

void command_limpa() {
  int pid = fork ();
  char **argv = NULL;
  int error_clear;
  if(pid == 0) {
    // processo filho
    error_clear = execvp("/bin/clear", argv);
    if(error_clear == -1){  
      printf("ERROR: SHELL NAO PODE EXECUTAR O COMANDO NO DIRETORIO\n");
      exit(0);
    }
  } else {
    // processo pai
    wait(0) ;
  }
}

int command_validate_dir(char *path) {
  DIR* dir = opendir(path);
  if (dir) {
    closedir(dir);
    return 1;
  } else if (ENOENT == errno) {
    return 0;
  } else {
    return -1;
  }
}
