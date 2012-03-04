/******************************************************************************
    random.cpp
 ******************************************************************************/
#include "random.h"
#include <stdlib.h>


//-----------------------------------------------------------------------------
double Random::random()
{
    return ((double)rand() / (double)RAND_MAX);
}


//-----------------------------------------------------------------------------
int Random::random(int scale)
{
    return (random() * scale);
}


//-----------------------------------------------------------------------------
bool Random::choice()
{
    return (random() > 0.5);
}


//-----------------------------------------------------------------------------
double Random::randomAngle(double initial, double deviation)
{
    // Random deviation
    double randomDeviation = (random() * deviation);
    if (choice()) {
        randomDeviation *= -1;
    }

    // Scale
    double radians = (((initial + randomDeviation) * (2.0 * 3.141)) / 360.0);

    return -radians;
}
