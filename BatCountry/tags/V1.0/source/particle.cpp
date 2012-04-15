/*  particle.cpp
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
#include "particle.h"
#include "graphics/images.h"
#include <math.h>


//-----------------------------------------------------------------------------
Particle::Particle(int x, int y, double angle, double velocity, const Element& element, const Rect& worldRect) :
    WorldObject(x, y),
    _state(sActive),
    _worldRect(worldRect),
    _element(element),
    _updateTimer("particle_update_timer"),
    _activeTimer("particle_active_timer")
{

    _x = x;
    _y = y;
    _velocity = velocity;
    _gravity = 0.1;
    _angle = angle;

    _velocityX = _velocity * cos(_angle);
    _velocityY = _velocity * sin(_angle);

}


//-----------------------------------------------------------------------------
Particle::~Particle()
{

}


//-----------------------------------------------------------------------------
Rect Particle::boundingRect() const
{
    return Rect::centerAroundPoint(_position, 1, 1);
}


//-----------------------------------------------------------------------------
void Particle::update()
{
    if (_state == sActive) {
    
        if (_updateTimer.elapsed() > 0.050) {


             _x += _velocityX;
             _y += _velocityY;

             // update velocity
             _velocityY += _gravity;

            _position.setX(_x);
            _position.setY(_y);
            if (!_worldRect.contains(_position)) {
                _state = sExpired;
            }

            _updateTimer.reset();
        }

        if (_activeTimer.elapsed() > 0.800) {
            _state = sExpired;
        }
    }
}


//-----------------------------------------------------------------------------
void Particle::render(Canvas& canvas)
{
    canvas.drawElement(_element, _position.x(), _position.y());    
}
