#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void test1(){
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

    printf("_______________________________________________________________________________________________\n");
    printf("______________________________TEST (villageEffect) First Player________________________________\n");
        //printState(&gInit, players);
        villageEffect(currentPlayer, &g, handPos);
        //printState(&g, players);
        int t = assert(gInit.deckCount[currentPlayer]-1, g.deckCount[currentPlayer]);
        if(t){
            printf("PASSED: deck decrimented by 1.\n");
        }
        else{
            printf("FAILED: deck was not decrimented by 1.\n");
        }
        t = assert(gInit.handCount[currentPlayer], g.handCount[currentPlayer]);
        if(t){
            printf("PASSED: hand incrimented by 1.\n");        }
        else{
            printf("FAILED: hand was not incrimented by 1.\n");
        }
       
   
        t = assert(gInit.numActions+2, g.numActions);
        if(t){
            printf("PASSED: actions incrimented by 2.\n");
        
        }
        else{
            printf("FAILED: actions was not incrimented by 2.\n");
        }       
        
        printf("________________________________________________________________________________________________\n");
        printf("______________________________ TEST (villageEffect) Second Player ______________________________\n");

        t = assert(gInit.deckCount[otherPlayer], g.deckCount[otherPlayer]);
        if(t){
            printf("PASSED: deck was not changed for second player.\n");
        }
        else{
            printf("FAILED: deck was changed for second player.\n");
        }
        t = assert(gInit.handCount[otherPlayer], g.handCount[otherPlayer]);
        if(t){
            printf("PASSED: hand was not changed for second player.\n");        }
        else{
            printf("FAILED: hand was changed for second player.\n");
        }
        

}
