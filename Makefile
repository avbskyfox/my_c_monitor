#Makefile for project_one

project_one_exec: main.o function.o
	gcc -m32 -s -lncurses -o project_one_exec_32 main.o function.o
	gcc -m32 -s -static -lncurses -o project_one_exec_32_static main.o function.o

main.o: main.c
	gcc -m32 -c main.c

function.o: function.c
	gcc -m32 -c function.c

clean:
	rm -f *.o project_one_exec