#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/APNG.h"

float max(float a, float b){
    if(a>b) return a;
    else return b;
}

int PoissonUncertaintyCollapseFunction(UnstableTimeUnit* unit){
    unsigned int value = RAND_MAX * (unit->t / unit->tau);
    unit->t++;
    if(rand() < value){
        #ifdef DUNITVAL
        printf("%d,",unit->t);
        #endif
        unit->t = 0;
        return 1;
    }else return 0;
}

int ExponentialDecayUncertaintyCollapseFunction(UnstableTimeUnit* unit){
    unsigned int value = RAND_MAX / unit->tau;
    unit->t++;
    if(rand() < value){
        #ifdef DUNITVAL
        printf("%d,",unit->t);
        #endif
       unit->t = 0;
        return 1;
    }else return 0;
}

int ReversePoissonUncertaintyCollapseFunction(UnstableTimeUnit* unit){
    unsigned int value = RAND_MAX * (pow(unit->sigma,unit->t - unit->tau));
    unit->t++;
    if(rand() < value){
        #ifdef DUNITVAL
        printf("%d,",unit->t);
        #endif
        unit->t = 0;
        return 1;
    }else return 0;
}

int LinearDecayUncertaintyCollapseFunction(UnstableTimeUnit* unit){
    unsigned int value = RAND_MAX * (-2/(unit->t-unit->tau));
    unit->t++;
    if(rand() < value){
        #ifdef DUNITVAL
        printf("%d,",unit->t);
        #endif
        unit->t = 0;
        return 1;
    }else return 0;
}

int NormalEnoughUncertaintyCollapseFunction(UnstableTimeUnit* unit){
    unsigned int value = RAND_MAX * (1 / (1 + exp((unit->tau - unit->t) / unit->sigma)))* (1/unit->sigma);
    unit->t++;
    if(rand() < value){
        #ifdef DUNITVAL
        printf("%d,",unit->t);
        #endif
        unit->t = 0;
        return 1;
    }else return 0;
}

int NormalEnoughUncertainIntegerGenerator(){
    float x = rand()/(float)RAND_MAX;
    float div = atanh(x);
    div *= RAND_MAX >> 3;
    return (RAND_MAX>>1) + (rand() & 1 ? div : -div);
}
