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
// The probability of success follow an exponential charge law
// You can expect a 63% success rate at Tau time
// And 95% success at 3xTau time
int ExponentialUnstableTimeUnitCollapse(UnstableTimeUnit* unit);

#endif