#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/APNG.h"

int LinearUncertaintyCollapseFunction(UnstableTimeUnit* unit){
    int value = RAND_MAX * (unit->t / unit->tau);
    unit->t++;
    if(rand() < value){
        unit->t = 0;
        return 1;
    }else return 0;
}

int SigmoidUncertaintyCollapseFunction(UnstableTimeUnit* unit){
    int value = RAND_MAX * (1 / (1 + exp(unit->tau / unit->sigma - unit->t / unit->sigma)));
    unit->t++;
    if(rand() < value){
        unit->t = 0;
        return 1;
    }else return 0;
}