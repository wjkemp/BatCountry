/*  rocket.cpp
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
#include "rocket.h"
#include "utilities/random.h"


//-----------------------------------------------------------------------------
Rocket::Rocket(
    double x,
    double y,
    double directionX,
    double directionY,
    int damage,
    double velocity,
    const Rect& activeRect,
    const Element& element) :
    Bullet(x, y, damage, activeRect, element),
    _x(x),
    _y(y),
    _directionX(directionX),
    _directionY(directionY),
    _velocity(velocity)
{

}


//-----------------------------------------------------------------------------
Rocket::~Rocket()
{

}


//-----------------------------------------------------------------------------
void Rocket::update()
{
    if (_state == sActive) {
    
        double time = _updateTimer.elapsed();

        _x += _directionX * _velocity * time;
        _y += _directionY * _velocity * time;
        _position.setX(_x);
        _position.setY(_y);
            
        if (!_activeRect.contains(_position)) {
            _state = sExpired;
        }

        _updateTimer.reset();
    }
}


//-----------------------------------------------------------------------------
std::list<Particle*> Rocket::spawnResidue() const
{
    std::list<Particle*> particles;

    // High Base Velocity
    double effectVelocity = 2.0;

    // Spawn particles
    for (int i=0; i < 10; ++i) {
        double velocity;
        velocity = (Random::random() * 0.8) + effectVelocity;
        Particle* particle = new Particle(_position.x(), _position.y(), Random::randomAngle(90, 120), velocity, Element('.', COLOR_WHITE), Rect::centerAroundPoint(_position, 16, 16));
        particles.push_back(particle);
    }


    return particles;
}
