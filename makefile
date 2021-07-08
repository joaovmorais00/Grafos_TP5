all: main

main: main.c tp5.o 
	gcc -O3 tp5.o main.c -o main  -w

tp5.o: tp5.c tp5.h
	gcc -O3 -c  tp5.c  -w

clear:
	rm *.o