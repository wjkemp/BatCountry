/******************************************************************************
   genericbullet.h
 ******************************************************************************/
#ifndef __GENERICBULLET_H__
#define __GENERICBULLET_H__

#include "bullet.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class GenericBullet : public Bullet
{

public:
    GenericBullet(
        double x,
        double y,
        double directionX,
        double directionY,
        int damage,
        double velocity,
        const Rect& activeRect,
        const Element& element);
    ~GenericBullet();
    void update();

private:
    double _x;
    double _y;
    double _directionX;
    double _directionY;
    double _velocity;
};



#endif
