/******************************************************************************
   demonbat.h
 ******************************************************************************/
#ifndef __DEMONBAT_H__
#define __DEMONBAT_H__

#include "enemy.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class DemonBat : public Enemy
{
public:
    enum MovementState
    {
        sMovingLeft,
        sMovingRight
    };

public:
    DemonBat(const Rect& area, double velocityBase);
    ~DemonBat();

    Rect boundingRect() const;
    void update();
    void render(Canvas& canvas);
    std::list<Particle*> spawnParticles();
    int reward() const { return 25; }
    double randomAngle(double initial, double deviation);
    
private:
    Rect _area;
    double _x;
    double _velocityVariation;
    double _velocity;
    MovementState _movementState;
    Bitmap _animationA;
    Bitmap _animationB;
    Bitmap _animationC;
    Timer _animationTimer;
    Timer _movementTimer;
    std::list<Bitmap*> _animation;
    std::list<Bitmap*>::iterator _animationIndex;

};



#endif
