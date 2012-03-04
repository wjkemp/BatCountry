/******************************************************************************
   rifle.h
 ******************************************************************************/
#ifndef __RIFLE_H__
#define __RIFLE_H__

#include "weapon.h"
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Rifle : public Weapon
{

public:
    Rifle();
    ~Rifle();
    std::string fullName() const            { return "Rifle"; }
    std::string shortName() const           { return "Rifle"; }
    int itemPrice() const                   { return 300; }
    int ammunitionBundlePrice() const       { return 50; }
    int ammunitionBundleSize() const        { return 50; }
    std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea);

};



#endif
