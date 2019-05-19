#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "randomtestcard1.h"
#include "randomhelpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomVillageTest(){
    //game setup
    srand(time(0));
    //int players = randInt(1, MAX_PLAYERS);
    struct gameState g;
    struct gameState gInit;
    for(int i = 0; i < 10000; i++){
        //////create random gamestate//////
        gInit.numPlayers        = randInt(2, MAX_PLAYERS);
        gInit.outpostPlayed     = randInt(0, 5);
        gInit.outpostTurn       = randInt(0, gInit.numPlayers-1);
        gInit.whoseTurn         = randInt(0, gInit.numPlayers-1);
        gInit.phase             = randInt(0,1);
        gInit.numActions        = randInt(1,5);
        gInit.coins             = randInt(0,10);
        gInit.numBuys           = randInt(1,1);
        gInit.playedCardCount   = randInt(0, gInit.numActions);

        for(int i = 0; i < treasure_map+1; i++){
            gInit.supplyCount[i]    = randInt(0, 20);
            gInit.embargoTokens[i]  = randInt(0,20);
        }
        for(int i = 0; i < gInit.numPlayers; i++){
            gInit.handCount[i]      = randInt(1, MAX_HAND);
            gInit.deckCount[i]      = randInt(1, MAX_DECK);
            gInit.discardCount[i]   = randInt(0, MAX_DECK);

            for(int j = 0; j < gInit.deckCount[i]; j++){
                gInit.deck[i][j]    = randInt(curse, treasure_map);
            }
            for(int j = 0; j < gInit.handCount[i]; j++){
                gInit.hand[i][j]    = randInt(curse, treasure_map);
            }
            for(int j = 0; j < gInit.discardCount[i]; j++){
                gInit.discard[i][j] = randInt(curse, treasure_map);
            }
        }
        for(int j = 0; j < MAX_DECK; j++){
            gInit.playedCards[j]    = 0;
        }

        //game setup finished
        //test setup
        memcpy(&gInit, &g, sizeof(struct gameState));
        int handPos = randInt(0, gInit.handCount[0]);
        int currentPlayer = gInit.whoseTurn;
        int otherPlayer = currentPlayer;
        while(otherPlayer != currentPlayer){
            otherPlayer = randInt(0, gInit.numPlayers-1);
        }
        
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
        memset(&gInit, 0, sizeof(struct gameState));
        memset(&g, 0, sizeof(struct gameState));
    }
}