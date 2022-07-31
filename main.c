#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/APNG.h"

#define STDLEN 50

int main(int argc, char** argv){

    srand(time(NULL));
    
    UnstableTimeUnit test;
    test.t = 0;
    test.tau = 1;
    test.sigma = 4;
    
    unsigned int probs[STDLEN] = {0};
    unsigned int i,k=0,l=0;

    for(l = 5 ; l < 301 ; l++){
        test.tau = l;
        for(k = 0 ; k < 10000 ; k++){
            for(i = 0 ; !LinearUncertaintyCollapseFunction(&test) ; i++);
            if(i < STDLEN) probs[i]++;
            // printf("\n");
            // for(int j = 0 ; j < STDLEN ; j++) printf("%d,",probs[j]);
        }
        int tmp = 0;
        for(int j = 0; j < STDLEN ; j++) tmp = (probs[j] > tmp) ? j : tmp;
        for(int j = 0; j < STDLEN ; j++) probs[j] = 0;
        printf("%d,",tmp);
    }
    
    return 0;
}