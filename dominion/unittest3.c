#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void test3(){
    //game setup
    int players = 2;
    struct gameState g;
    struct gameState gInit;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy};
    int initGame = initializeGame(players, k, 1000, &g);
    //game setup finished
    //test setup
    memcpy(&gInit, &g, sizeof(struct gameState));
    int handPos = 0;
    int currentPlayer = 0;
    int otherPlayer = 1;
    //run tests
    printf("____________________________________________________________________________________________________\n");
    printf("______________________________TEST (counsil_roomEffect) First Player________________________________\n");
        //printState(&gInit, players);
        counsil_roomEffect(currentPlayer, &g, handPos);
        //printState(&g, players);
        int t = assert(gInit.deckCount[currentPlayer]-4, g.deckCount[currentPlayer]);
        if (t == 1){
            printf("PASSED: deck decrimented by 4.\n");
        }
        else{
            printf("FAILED: deck was not decrimented by 4.\n");
        }
        t = assert(gInit.handCount[currentPlayer]+3, g.handCount[currentPlayer]);
        if (t == 1){
            printf("PASSED: hand incrimented by 4.\n");
        }
        else{
            printf("FAILED: hand was not incrimented by 4.\n");
        }
   
        t = assert(gInit.numBuys+1, g.numBuys);
        if (t == 1){
        printf("PASSED: numBuys incrimented by 1.\n");
        }
        else{
            printf("FAILED: numBuys was not incrimented by 1.\n");
        }

        printf("____________________________________________________________________________________________________\n");
        printf("______________________________TEST (counsil_roomEffect) Second Player_______________________________\n");

        t = assert(gInit.deckCount[otherPlayer]-1, g.deckCount[otherPlayer]);
        if (t == 1){
            printf("PASSED: deck was decrimented 1 by for second player.\n");
        }
        else{
            printf("FAILED: deck was not decrimented by 1 for second player.\n");
        }
        t = assert(gInit.handCount[otherPlayer]+1, g.handCount[otherPlayer]);
        if (t == 1){
            printf("PASSED: hand was incrimented by 1 for second player.\n");
        }
        else{
            printf("FAILED: hand was not incrimented by 1 for second player.\n");
        }
   

}
