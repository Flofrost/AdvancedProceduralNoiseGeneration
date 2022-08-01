#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/APNG.h"

#define STDLEN 100

int main(int argc, char** argv){

    srand(time(NULL));
    
    UnstableTimeUnit test;
    test.t = 0;
    test.tau = 50;
    test.sigma = 10;
    
    unsigned int probs[STDLEN] = {0};
    int i,k=0;

    while(k++ < 1000000){
        for(i = 0 ; !PoissonUncertaintyCollapseFunction(&test) ; i++);
        if(i < STDLEN) probs[i]++;
        i = 0;
    }

    for(int j = 0 ; j < STDLEN ; j++) printf("%d,",probs[j]);
    printf("\n");

    return 0;
}