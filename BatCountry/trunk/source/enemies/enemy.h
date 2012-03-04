/******************************************************************************
   enemy.h
 ******************************************************************************/
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "worldobject.h"
#include "graphics/bitmap.h"
#include "utilities/timer.h"
#include "particle.h"
#include <list>

//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Enemy : public WorldObject
{

public:
    enum State
    {
        sActive,
        sKilled,
        sEscaped
    };

public:
    Enemy(int health);
    ~Enemy();
    State state() const { return _state; }
    void damage(int damage);
    virtual std::list<Particle*> spawnParticles() = 0;
    virtual int reward() const = 0;

protected:
    int _health;
    State _state;

};



#endif
