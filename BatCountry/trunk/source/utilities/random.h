/******************************************************************************
    random.h
 ******************************************************************************/
#ifndef __RANDOM_H__
#define __RANDOM_H__


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Random
{

public:
    static double random();
    static int random(int scale);
    static bool choice();
    static double randomAngle(double initial, double deviation);
};



#endif
