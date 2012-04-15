/*  particle.h
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
