/******************************************************************************
   bullet.h
 ******************************************************************************/
#ifndef __BULLET_H__
#define __BULLET_H__

#include "worldobject.h"
#include "graphics/element.h"
#include "utilities/timer.h"
#include "particle.h"
#include <list>



//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Bullet : public WorldObject
{
public:
    enum State
    {
        sActive,
        sExpired
    };


public:
    Bullet(
        double x,
        double y,
        int damage,
        const Rect& activeRect,
        const Element& element);
    ~Bullet();

    State state() const { return _state; }
    int damage() const { return _damage; }

    Rect boundingRect() const;
    void render(Canvas& canvas);

    virtual bool hasRadiusDamage() const;
    virtual double damageRadius() const;
    virtual std::list<Particle*> spawnResidue() const;
    
    
protected:
    State _state;
    int _damage;
    Rect _activeRect;
    Element _element;
    Timer _updateTimer;

};



#endif
