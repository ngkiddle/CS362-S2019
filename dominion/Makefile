CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

unittest_helpers.o: unittest_helpers.h unittest_helpers.c dominion.o rngs.o*
	gcc -c unittest_helpers.c dominion.o rngs.o $(CFLAGS)

unittest1.o: unittest1.h unittest1.c unittest_helpers.o dominion.o rngs.o*  
	gcc -c unittest1.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

unittest2.o: unittest2.h unittest2.c unittest_helpers.o dominion.o rngs.o*  
	gcc -c unittest2.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

unittest3.o: unittest3.h unittest3.c unittest_helpers.o dominion.o rngs.o*  
	gcc -c unittest3.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

unittest4.o: unittest4.h unittest4.c unittest_helpers.o dominion.o rngs.o*  
	gcc -c unittest4.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

cardtest4.o: cardtest1.h cardtest1.c unittest_helpers.o dominion.o rngs.o*  
	gcc -c cardtest1.c unittest_helpers.o dominion.o rngs.o $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittestresult: unittests.c  unittest_helpers.o unittest1.o unittest2.o unittest3.o unittest4.o cardtest1.o dominion.o rngs.o*  
	gcc -o unittest -g unittests.c unittest_helpers.o unittest1.o unittest2.o unittest3.o unittest4.o cardtest1.o dominion.o rngs.o $(CFLAGS)
	./unittest > unittestresult.out
	gcov dominion.c >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
