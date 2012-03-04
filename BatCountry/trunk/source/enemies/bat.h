/******************************************************************************
   bat.h
 ******************************************************************************/
#ifndef __BAT_H__
#define __BAT_H__

#include "enemy.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Bat : public Enemy
{
public:
    enum AnimationState
    {
        sAnimateA,
        sAnimateB
    };

    enum MovementState
    {
        sMovingLeft,
        sMovingRight
    };

public:
    Bat(const Rect& area, double velocityBase);
    ~Bat();

    Rect boundingRect() const;
    void update();
    void render(Canvas& canvas);
    std::list<Particle*> spawnParticles();
    int reward() const { return 10; }
    double randomAngle(double initial, double deviation);
    
private:
    Rect _area;
    double _x;
    double _velocityVariation;
    double _velocity;
    AnimationState _animationState;
    MovementState _movementState;
    Bitmap _animationA;
    Bitmap _animationB;
    Timer _animationTimer;
    Timer _movementTimer;

};



#endif
