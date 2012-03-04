/******************************************************************************
   rocketlauncher.h
 ******************************************************************************/
#ifndef __ROCKETLAUNCHER_H__
#define __ROCKETLAUNCHER_H__

#include "weapon.h"
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class RocketLauncher : public Weapon
{

public:
    RocketLauncher();
    ~RocketLauncher();
    std::string fullName() const            { return "Rocket Launcher"; }
    std::string shortName() const           { return "Rockets"; }
    int itemPrice() const                   { return 1000; }
    int ammunitionBundlePrice() const       { return 200; }
    int ammunitionBundleSize() const        { return 10; }
    std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea);

};



#endif
