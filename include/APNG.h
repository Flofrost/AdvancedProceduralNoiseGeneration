#ifndef APNG_H
#define APNG_H

// Object that dictates when events are triggered
// Events are triggered at random time intervals, but the average time interval can be controlled
typedef struct UnstableTimeUnit{
    // t is for time, incremeted each evaluation, and reset on successful trigger
    unsigned int t;
    // tau is the time constant, controlls "when" a trigger should happen
    float tau;
    // sigma can control the standard deviation
    float sigma;
}UnstableTimeUnit;

// Returns a boolean based on a random decision
// The probability of success follow an linearlaw
// You can expect a 50% success on tau/2 th try
// And garanteed sucvess on the tau-th try
int LinearUncertaintyCollapseFunction(UnstableTimeUnit* unit);


int SigmoidUncertaintyCollapseFunction(UnstableTimeUnit* unit);

#endif