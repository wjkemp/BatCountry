/*  bullet.h
 *
 *  Copyright (C) 2012 Willem Kemp <http://www.thenocturnaltree.com/>
 *  All rights reserved.
 *
 *  This file is part of BatCountry.
 *
 *  BatCountry is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  BatCountry is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with BatCountry. If not, see http://www.gnu.org/licenses/.
 *
 */
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
    virtual ~Bullet();

    State state() const { return _state; }
    int damage() const { return _damage; }

    Rect boundingRect() const;
    void render(Canvas& canvas);

    virtual bool hasRadiusDamage() const;
    virtual double damageRadius() const;
    virtual std::list<Particle*> spawnResidue() const;
    virtual bool intersects(const Rect& rect) const;
    
    
protected:
    double _x;
    double _y;
    State _state;
    int _damage;
    Rect _activeRect;
    Element _element;
    Timer _updateTimer;

};



#endif
