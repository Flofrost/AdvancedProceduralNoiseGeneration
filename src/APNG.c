#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/APNG.h"

int ExponentialUnstableTimeUnitCollapse(UnstableTimeUnit* unit){
    int value = RAND_MAX * (1 - exp(-(unit->t/unit->tau)));
    unit->t = unit->t + 1;
    if(rand() < value){
        unit->t = 0;
        return 1;
    }else return 0;
}