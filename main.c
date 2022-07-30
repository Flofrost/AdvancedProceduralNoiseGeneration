#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/APNG.h"

#define STDLEN 50

int main(int argc, char** argv){

    srand(time(NULL));
    
    UnstableTimeUnit test;
    test.t = 0;
    test.tau = 4;
    test.sigma = 25;
    
    unsigned int probs[STDLEN] = {0};
    int i;

    while(1){
        for(i = 0 ; !SigmoidUncertaintyCollapseFunction(&test) ; i++);
        probs[i]++;
        i = 0;
        printf("\n");
        for(int j = 0 ; j < STDLEN ; j++) printf("%d,",probs[j]);
    }

    return 0;
}