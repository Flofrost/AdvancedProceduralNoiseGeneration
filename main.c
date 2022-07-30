#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/APNG.h"

int main(int argc, char** argv){

    srand(time(NULL));
    
    UnstableTimeUnit test;
    test.t = 0;
    test.tau = 50;
    
    int i;
    for(i = 0 ; !ExponentialUnstableTimeUnitCollapse(&test) ; i++);
    printf("%d\n",i);

    return 0;
}