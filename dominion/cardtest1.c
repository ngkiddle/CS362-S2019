#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void cardtest1(){
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
    int z = 0;
    //run tests
    printf("____________________________________________________________________________________________________\n");
    printf("______________________________TEST (adventurerEffect) First Player__________________________________\n");
        //printState(&gInit, players);
        adventurerEffect(currentPlayer, &g, 2, 0, 1, z);
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
// int adventurerEffect(int currentPlayer, struct gameState *state, int drawntreasure, int cardDrawn, int temphand, int z){
//     while(drawntreasure<2){
// 	    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
// 	        shuffle(currentPlayer, state);
// 	    }
// 	    drawCard(currentPlayer, state);
// 	    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
// 	    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
// 	        drawntreasure++;
// 	    else{
// 	        temphand[&z]=cardDrawn;
// 	        state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
// 	        z++;
// 	    }
//       }
//     while(z-1>=0){
// 	   state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[&z-1]; // discard all cards in play that have been drawn
// 	   z=z-1;
//     }
//     //return 0; 
//     return -1; //T
// }