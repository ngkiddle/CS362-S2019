CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer.o: randomtestadventurer.h randomtestadventurer.c
	gcc -c randomtestadventurer.c $(CFLAGS)

randomtestcard1.o: randomtestcard1.h randomtestcard1.c
	gcc -c randomtestcard1.c $(CFLAGS)

randomtestcard2.o: randomtestcard2.h randomtestcard2.c
	gcc -c randomtestcard2.c $(CFLAGS)

randomhelpers.o: randomhelpers.h randomhelpers.c
	gcc -c randomhelpers.c $(CFLAGS)
	
randomtestresults: randomtests.c randomhelpers.o randomtestcard1.o randomtestcard2.o randomtestadventurer.o dominion.o rngs.o
	gcc -o rand randomtests.c randomhelpers.o randomtestcard1.o randomtestcard2.o randomtestadventurer.o -g dominion.o rngs.o $(CFLAGS) > randomtestresults.out
	./rand >> randomtestresults.out
	gcov -bfc dominion.c | grep -A 2 adventurerEffect >> randomtestresults.out
	gcov -bfc dominion.c | grep -A 2 villageEffect >> randomtestresults.out
	gcov -bfc dominion.c | grep -A 2 counsil_roomEffect >> randomtestresults.out

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
