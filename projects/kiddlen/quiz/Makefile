CFLAGS= -Wall -fpic -coverage -lm -std=c99
make: testme.c
	gcc testme.c -o testme $(CFLAGS)
	- ./testme
	gcov -b testme.c
