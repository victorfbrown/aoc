aoc:
	gcc -c utils.c
	gcc -c main.c
	gcc main.o utils.o -o main

run:
	./main