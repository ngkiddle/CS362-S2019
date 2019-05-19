#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "randomtestadventurer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt (int low, int high){
    int num = (rand()%(high - low+1)) + low;
    return num;
}

int assert(int a, int b){
    if (a==b){
        return 1;
    }
    else{
        return 0;
    }
}

void testAdventurer(){
    //game setup
    srand(time(0));
    //int players = randInt(1, MAX_PLAYERS);
    struct gameState g;
    struct gameState gInit;

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
    int z = 0;
    int currentPlayer = gInit.whoseTurn;
    int numPlayers = gInit.numPlayers;
    int otherPlayer = currentPlayer;
    while(otherPlayer != currentPlayer){
        otherPlayer = randInt(0, gInit.numPlayers-1);
    }
    for(int i = 0; i < 10000; i++){
        //run tests
        printf("____________________________________________________________________________________________________\n");
        printf("______________________________TEST (adventurerEffect) First Player__________________________________\n");
            //printState(&gInit, players);
            adventurerEffect(currentPlayer, &g, 0, 0, 0, z);
            //printState(&g, players);
            int t = assert(gInit.deckCount[currentPlayer], g.deckCount[currentPlayer]);
            if (t == 1){
                printf("PASSED: no changes were made to state.\n");
            }
            else{
                printf("FAILED: no changes were made to state.\n");
            }
            ////////////////////////
            t = assert(gInit.handCount[currentPlayer], g.handCount[currentPlayer]);
            if (t == 1){
                printf("PASSED: no changes were made to state.\n");
            }
            else{
                printf("FAILED: no changes were made to state.\n");
            }
            //////////////
            t = assert(gInit.discardCount[currentPlayer], g.discardCount[currentPlayer]);
            if (t == 1){
                printf("PASSED: no changes were made to state.\n");
            }
            else{
                printf("FAILED: no changes were made to state.\n");
            }

        


            printf("____________________________________________________________________________________________________\n");
            printf("______________________________TEST (adventurerEffect) Second Player_________________________________\n");

            t = assert(gInit.deckCount[otherPlayer], g.deckCount[otherPlayer]);
            if (t == 1){
                printf("PASSED: no changes were made to state for second player.\n");
            }
            else{
                printf("FAILED: changes were made to state for second player.\n");
            }
                    t = assert(gInit.handCount[otherPlayer], g.handCount[otherPlayer]);
            if (t == 1){
                printf("PASSED: no changes were made to state.\n");
            }
            else{
                printf("FAILED: no changes were made to state.\n");
            }
            //////////////
            t = assert(gInit.discardCount[otherPlayer], g.discardCount[otherPlayer]);
            if (t == 1){
                printf("PASSED: no changes were made to state.\n");
            }
            else{
                printf("FAILED: no changes were made to state.\n");
            }

        memcpy(&g, &gInit, sizeof(struct gameState));

        printf("__________________________________________________________________________________________________________________\n");
        printf("______________________________TEST (adventurerEffect) First Player for z = 10_____________________________________\n");
            //printState(&gInit, players);
            z = 10;
            adventurerEffect(currentPlayer, &g, 2, 0, 1, z);
            //printState(&g, players);
            t = assert(gInit.discardCount[currentPlayer]+10, g.discardCount[currentPlayer]);
            if (t == 1){
                printf("PASSED: discard was increased by 10 for z = 10.\n");
            }
            else{
                printf("FAILED: discard was not increased by 10 for z = 10.\n");
            }
    


            printf("______________________________________________________________________________________________________________\n");
            printf("______________________________TEST (adventurerEffect) Second Player z = 10____________________________________\n");

            t = assert(gInit.discardCount[otherPlayer], g.discardCount[otherPlayer]);
            if (t == 1){
                printf("PASSED: no changes were made to discard for second player.\n");
            }
            else{
                printf("FAILED: changes were made to discard for second player.\n");
            }
    }
}
