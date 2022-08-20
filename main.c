#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Flofrost/WavTools.h>
#include "include/APNG.h"

#define STDLEN 100

float evol(float tv, float v, void* p){
    if(v < tv) return v+7;
    else return v-7;
}

float eval(){
    float val = NormalEnoughUncertainIntegerGenerator()/(float)RAND_MAX;
    val -= 0.5;
    return 127 + val * 500;
}

int main(int argc, char** argv){

    srand(time(NULL));
    
    UnstableValueUnit test = {
        .timeUnit = {
            .t = 0,
            .tau = 10,
            .sigma = 2
        },
        .UncertaintyCollapseFunction = LinearDecayUncertaintyCollapseFunction,
        .value = 127,
        .targetValue = 127,
        .EvaluationFunction = eval,
        .EvolutionFunction = evol
    };

    FILE* testFile = Wcreate("test.wav", 8000, 1, 8);

    for(int i = 0 ; i < 10 * 8000 ; i++){
        UnstableValueUnitProgressionFunction(&test);
        printf("%d,",(int)test.value);
        fputc((int)test.value,testFile);
    }

    Wclose(testFile);

    return 0;
}