/******************************************************************************
   shotgun.h
 ******************************************************************************/
#ifndef __SHOTGUN_H__
#define __SHOTGUN_H__

#include "weapon.h"
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Shotgun : public Weapon
{

public:
    Shotgun();
    ~Shotgun();
    std::string fullName() const            { return "Shotgun"; }
    std::string shortName() const           { return "Shotgun"; }
    int itemPrice() const                   { return 500; }
    int ammunitionBundlePrice() const       { return 50; }
    int ammunitionBundleSize() const        { return 20; }
    std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea);

};



#endif
