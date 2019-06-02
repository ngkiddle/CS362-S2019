#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void printState(struct gameState* state, int players){
    printf("----------------------------------------\n");
    printf("state->numPlayers:\t%d\n", state->numPlayers);
    printf("state->whoseTurn:\t%d\n", state->whoseTurn);
    printf("state->playedCardCount: %d\n", state->playedCardCount);
    printf("state->whoseTurn:\t%d\n", state->whoseTurn);
    printf("state->numActions:\t%d\n", state->numActions);
    printf("state->coins:\t%d\n", state->coins);
    printf("state->numBuys:\t%d\n", state->numBuys);



    for (int i = 0; i < players; i++){
        printf("--------------PLAYER %d-------------\n",i);
        printf("state->deckCount[%d]:\t%d\n", i, state->deckCount[i]);
        printf("state->discardCount[%d]:\t%d\n", i, state->discardCount[i]);
        printf("state->handCount[%d]:\t%d\n", i, state->handCount[i]);
        // for(int j = 0; j < state->deckCount[i]; j++){
        //     printf("state->deck[%d][%d]:\t%d\n", i, j, state->deck[i][j]);

        // }
        // for (int f = 0; f < state->discardCount[i]; f++){
        //     printf("state->discard[%d][%d]:\t%d\n", i, f, state->discard[i][f]);
        // }
    }
}

int assert(a,b){
    if (a==b){
        return 1;
    }
    else{
        return 0;
    }
}