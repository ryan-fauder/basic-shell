STD = -std=c++17

OPTIONS = -g -O0
# -Wall -Wpedantic -Wno-unused-result -O0 -g
# -O0: nao otimiza o codigo ao compilar
# -g:  usa o gdb possa encontrar bugs

LIBRARIES = -lm

SOURCES = historico.h historico.c stack.h stack.c utils.h utils.c config.c



.PHONY: run
run:
	gcc $(filter-out $@,$(MAKECMDGOALS)).c $(SOURCES) $(OPTIONS) -o main $(LIBRARIES)
%:
    @:
	

# Command to execute:
# make run main && ./main