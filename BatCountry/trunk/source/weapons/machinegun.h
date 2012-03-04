/******************************************************************************
   machinegun.h
 ******************************************************************************/
#ifndef __MACHINEGUN_H__
#define __MACHINEGUN_H__

#include "weapon.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Machinegun : public Weapon
{

public:
    Machinegun();
    ~Machinegun();
    std::string fullName() const            { return "Machinegun"; }
    std::string shortName() const           { return "Machinegun"; }
    int itemPrice() const                   { return 200; }
    int ammunitionBundlePrice() const       { return 100; }
    int ammunitionBundleSize() const        { return 50; }
    std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea);

};



#endif
