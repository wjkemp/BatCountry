/******************************************************************************
   grenadelauncher.h
 ******************************************************************************/
#ifndef __GRENADELAUNCHER_H__
#define __GRENADELAUNCHER_H__

#include "weapon.h"
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class GrenadeLauncher : public Weapon
{

public:
    GrenadeLauncher();
    ~GrenadeLauncher();
    std::string fullName() const            { return "Grenade Launcher"; }
    std::string shortName() const           { return "Grenades"; }
    int itemPrice() const                   { return 1000; }
    int ammunitionBundlePrice() const       { return 200; }
    int ammunitionBundleSize() const        { return 10; }
    std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea);

};



#endif
