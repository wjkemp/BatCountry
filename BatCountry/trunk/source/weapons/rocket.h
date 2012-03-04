/******************************************************************************
   rocket.h
 ******************************************************************************/
#ifndef __ROCKET_H__
#define __ROCKET_H__

#include "bullet.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Rocket : public Bullet
{

public:
    Rocket(
        double x,
        double y,
        double directionX,
        double directionY,
        int damage,
        double velocity,
        const Rect& activeRect,
        const Element& element);
    ~Rocket();
    void update();


    bool hasRadiusDamage() const { return true; }
    double damageRadius() const { return 10*10; }
    std::list<Particle*> spawnResidue() const;
    
private:
    double _x;
    double _y;
    double _directionX;
    double _directionY;
    double _velocity;
};



#endif
