pgm1: sort.o analyze.o read.o pgm1.o display.o
	gcc -o pgm1 functions.h sort.o analyze.o read.o display.o pgm1.o

read.o: read.c
	gcc -Wall -c read.c

analyze.o: analyze.c
	gcc -Wall -c analyze.c

sort.o: sort.c
	gcc -Wall -c sort.c

display.o: display.c
	gcc -Wall -c display.c

pgm1.o: pgm1.c
	gcc -Wall -c pgm1.c

