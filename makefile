STD = -std=c++17

OPTIONS = -g -O0
# -Wall -Wpedantic -Wno-unused-result -O0 -g
# -O0: nao otimiza o codigo ao compilar
# -g:  prepara o terreno para que o gdb possa encontrar bugs

LIBRARIES = -lm

MODULES = historico.h historico.c
% : 
	gcc $@.c $(MODULES) $(OPTIONS) -o main $(LIBRARIES)