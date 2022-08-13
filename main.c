#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Flofrost/WavTools.h>
#include "include/APNG.h"

#define STDLEN 100

int main(int argc, char** argv){

    srand(time(NULL));
    
    UnstableTimeUnit test;
    test.t = 0;
    test.tau = 1000;
    test.sigma = 100;
    
    FILE* fichier = Wcreate("test.wav", 8000, 1, 8);

    for(int i = 0 ; i < 80000 ; i++) fputc(NormalEnoughUncertaintyCollapseFunction(&test) ? 255 : 0, fichier);
    
    Wclose(fichier);

    return 0;
}