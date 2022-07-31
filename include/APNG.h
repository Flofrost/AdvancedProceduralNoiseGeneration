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
// The probability distribution follow a poisson-like law
// tau is used to control "when" the maximum of the distribution is
// Most successes may happen at 2.2 * tau ^ (1/1.9) + 2.5 tries
int LinearUncertaintyCollapseFunction(UnstableTimeUnit* unit);


int SigmoidUncertaintyCollapseFunction(UnstableTimeUnit* unit);


int OrderZeroUncertaintyCollapseFunction(UnstableTimeUnit* unit);

#endif