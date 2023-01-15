#ifndef __SHELL_H__
#define __SHELL_H__
#include "env.h"
#include "historico.h"
#include <stdio.h>

void interpreter(Env *env, History *history, FILE *stream);

#endif //__SHELL_H__