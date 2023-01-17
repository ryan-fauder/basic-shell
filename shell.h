#ifndef __SHELL_H__
#define __SHELL_H__
#include "env.h"
#include "historico.h"
#include <stdio.h>

/**
 * @brief Realiza o processo de interpretacao
 * 
 * @param env: Env *
 * @param history: History *
 * @param stream: FILE *
 */
void interpreter(Env *env, History *history, FILE *stream);

#endif //__SHELL_H__