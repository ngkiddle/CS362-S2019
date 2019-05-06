#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void test4(){
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
    int i = 0; 
    int j = 0;
    //run tests
    printf("____________________________________________________________________________________________________\n");
    printf("______________________________TEST (remodelEffect) First Player_____________________________________\n");
       // printState(&gInit, players);
        remodelEffect(currentPlayer, &g, 1, 2, handPos, i,j);
       // printState(&g, players);
    
       int t = assert(gInit.handCount[currentPlayer]-2, g.handCount[currentPlayer]);
        if (t == 1){
            printf("PASSED: hand decrimented by 3.\n");
        }
        else{
            printf("FAILED: hand was not decrimented by 3.\n");
        }
        t = assert(gInit.discardCount[currentPlayer]+1, g.discardCount[currentPlayer]);
        if (t == 1){
            printf("PASSED: discard incrimented by 1.\n");
        }
        else{
            printf("FAILED: discard was not incrimented by 1.\n");
        }

        printf("____________________________________________________________________________________________________\n");
        printf("______________________________TEST (remodelEffect) Second Player____________________________________\n");

        t = assert(gInit.handCount[otherPlayer], g.handCount[otherPlayer]);
        if (t == 1){
            printf("PASSED: hand was not changed for second player.\n");
        }
        else{
            printf("FAILED: hand was changed for second player.\n");
        }
        t = assert(gInit.discardCount[otherPlayer], g.discardCount[otherPlayer]);
        if (t == 1){
            printf("PASSED: discard was not changed for second player.\n");
        }
        else{
            printf("FAILED: discard was changed for second player.\n");
        }
   

}

// int remodelEffect(int currentPlayer, struct gameState *state, int choice1, int choice2, int handPos, int i, int j){
