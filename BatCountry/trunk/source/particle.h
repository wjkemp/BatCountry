/******************************************************************************
   particle.h
 ******************************************************************************/
#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include "worldobject.h"
#include "graphics/element.h"
#include "utilities/timer.h"



//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Particle : public WorldObject
{
public:

    enum State
    {
        sActive,
        sExpired
    };

public:
    Particle(
        int x,
        int y,
        double angle,
        double velocity,
        const Element& element,
        const Rect& worldRect);
    ~Particle();

    Rect boundingRect() const;
    void update();
    void render(Canvas& canvas);
    State state() const { return _state; }

private:
    double _x;
    double _y;
    double _velocityX;
    double _velocityY;
    double _gravity;
    double _velocity;
    double _angle;

    Rect _worldRect;
    State _state;
    Element _element;
    Timer _updateTimer;
    Timer _activeTimer;

};



#endif
