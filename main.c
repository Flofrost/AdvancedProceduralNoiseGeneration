#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Flofrost/WavTools.h>
#include "include/APNG.h"

#define STDLEN 100

int main(int argc, char** argv){

    srand(time(NULL));
    int hist[1024] = {0};

    for(int i = 0 ; i < 100000 ; i ++){
        int val = NormalEnoughUncertainIntegerGenerator() * (1024.0/RAND_MAX);
        hist[val]++;
    }

    for(int i = 0 ; i < 1024 ; i++) printf("%d,",hist[i]);
    
    return 0;
}