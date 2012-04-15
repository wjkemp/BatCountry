/*  random.cpp
 *
 *  Copyright (C) 2012 Willem Kemp <http://www.thenocturnaltree.com/>
 *  All rights reserved.
 *
 *  This file is part of BatCountry.
 *
 *  BatCountry is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  BatCountry is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with BatCountry. If not, see http://www.gnu.org/licenses/.
 *
 */
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
