STD = -std=c++17

OPTIONS = -g -O0
# -Wall -Wpedantic -Wno-unused-result -O0 -g
# -O0: nao otimiza o codigo ao compilar
# -g:  usa o gdb possa encontrar bugs

LIBRARIES = -lm

SOURCES = historico.h historico.c stack.h stack.c utils.h utils.c read.c read.h
SOURCES2 = config.c map.h map.c pair.c pair.h env.c env.h shell.c shell.h



.PHONY: run
run:
	gcc $(filter-out $@,$(MAKECMDGOALS)).c $(SOURCES) $(SOURCES2) $(OPTIONS) -o main $(LIBRARIES)
%:
    @:
	

# Command to execute:
# make run main && ./main