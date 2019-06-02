#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void test2(){
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

    printf("_______________________________________________________________________________________________\n");
    printf("______________________________ TEST (smithyEffect) First Player _______________________________\n");
        //printState(&gInit, players);
        smithyEffect(currentPlayer, &g, handPos, i);
        //printState(&g, players);
        int t = assert(gInit.deckCount[currentPlayer]-3, g.deckCount[currentPlayer]);
        if (t){
            printf("PASSED: deck decrimented by 3.\n");
        }
        else{
            printf("FAILED: deck was not decrimented by 3.\n");
        }
        t = assert(gInit.handCount[currentPlayer]+2, g.handCount[currentPlayer]);
        if (t){
            printf("PASSED: hand incrimented by 3.\n");
        }
        else{
            printf("FAILED: hand was not incrimented by 3.\n");
        }
        printf("_______________________________________________________________________________________________\n");
        printf("______________________________ TEST (smithyEffect) Second Player ______________________________\n");

        t = assert(gInit.deckCount[otherPlayer], g.deckCount[otherPlayer]);
        if (t){
            printf("PASSED: deck was not changed for second player.\n");
        }
        else{
            printf("FAILED: deck was changed for second player.\n");
        }
        t = assert(gInit.handCount[otherPlayer], g.handCount[otherPlayer]);
        if (t){
            printf("PASSED: hand was not changed for second player.\n");
        }
        else{
            printf("FAILED: hand was changed for second player.\n");
        }
}
