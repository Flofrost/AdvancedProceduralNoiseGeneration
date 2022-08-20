#ifndef APNG_H
#define APNG_H

// Object that dictates when events are triggered
// Events are triggered at random time intervals, but the average time interval can be controlled
typedef struct UnstableTimeUnit{
    // Time, incremeted each evaluation, and reset on successful trigger
    unsigned int t;
    // Parameter used to control "when" an event is triggered
    float tau;
    // Optionnal parameter to control deviation from the mean
    float sigma;
}UnstableTimeUnit;

// Object that contains a "value" that may change randomly
// How and when the value changes can be controlled using the other parameters in the struct
typedef struct UnstableValueUnit{
    // timeUnit determines when the value may change
    UnstableTimeUnit timeUnit;
    // The collapse function describes what method to use when evaluation the time unit
    int (*UncertaintyCollapseFunction)(UnstableTimeUnit*);
    // The famous value
    float value;
    // What value should the "value" be over time, usefulness dependant on the evolution function
    float targetValue;
    // Set of parameters passed as arguments for the evolution function
    void* params;
    // Method to use to make the value approach the target value
    // First argument is the target value, then the value, and then parameters
    // Returns new value
    float (*EvolutionFunction)(float, float, void*);
    // Function used to determine the next target value when the time unit is triggered
    float (*EvaluationFunction)();
}UnstableValueUnit;

// Returns a boolean based on a random decision
int PoissonUncertaintyCollapseFunction(UnstableTimeUnit* unit);

// Returns a boolean based on a random decision
int ExponentialDecayUncertaintyCollapseFunction(UnstableTimeUnit* unit);

// Returns a boolean based on a random decision
int ReversePoissonUncertaintyCollapseFunction(UnstableTimeUnit* unit);

// Returns a boolean based on a random decision
int LinearDecayUncertaintyCollapseFunction(UnstableTimeUnit* unit);

// Returns a boolean based on a random decision
int NormalEnoughUncertaintyCollapseFunction(UnstableTimeUnit* unit);

// Returns a random value with a normal distribution with an average of RAND_MAX / 2 and divergence of RAND_MAX / 100
int NormalEnoughUncertainIntegerGenerator();

// Updates the value of an UnstableValueUnit according to its evolution function
void UnstableValueUnitProgressionFunction(UnstableValueUnit* unit);

#endif