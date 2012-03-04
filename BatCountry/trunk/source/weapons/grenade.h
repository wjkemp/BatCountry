/******************************************************************************
   grenade.h
 ******************************************************************************/
#ifndef __GRENADE_H__
#define __GRENADE_H__

#include "bullet.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Grenade : public Bullet
{

public:
    Grenade(
        int x,
        int y,
        double angle,
        double velocity,
        int damage,
        const Rect& activeRect,
        const Element& element);
    ~Grenade();
    void update();


    bool hasRadiusDamage() const { return true; }
    double damageRadius() const { return 10*10; }
    std::list<Particle*> spawnResidue() const;
    
private:
    double _x;
    double _y;
    double _velocityX;
    double _velocityY;
    double _gravity;
    double _velocity;
    double _angle;

};



#endif
