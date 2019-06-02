#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randomhelpers.h"

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