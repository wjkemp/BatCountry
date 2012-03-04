/******************************************************************************
   pistol.h
 ******************************************************************************/
#ifndef __PISTOL_H__
#define __PISTOL_H__

#include "weapon.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Pistol : public Weapon
{

public:
    Pistol();
    ~Pistol();
    std::string fullName() const            { return "Pistol"; }
    std::string shortName() const           { return "Pistol"; }
    int itemPrice() const                   { return 0; }
    int ammunitionBundlePrice() const       { return 20; }
    int ammunitionBundleSize() const        { return 50; }
    std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea);

};



#endif
