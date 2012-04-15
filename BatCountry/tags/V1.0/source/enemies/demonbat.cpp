/*  demonbat.cpp
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
#include "demonbat.h"
#include "graphics/images.h"
#include "utilities/random.h"


//-----------------------------------------------------------------------------
DemonBat::DemonBat(const Rect& area, double velocityBase) :
    Enemy(6),
    _area(area),
    _velocityVariation(4),
    _movementState(sMovingRight),
    _animationA(IMG_DEMONBAT_A),
    _animationB(IMG_DEMONBAT_B),
    _animationC(IMG_DEMONBAT_C),
    _animationTimer("demonbat_animation_timer"),
    _movementTimer("demonbat_movement_timer")
{

    // Random height
    int y = _area.top() + (rand() % _area.height());

    // Velociry
    _velocity = velocityBase + (Random::random() * _velocityVariation); 

    // Start from an edge
    if (Random::choice()) {
        _x = area.left();
        _position.set(_area.left(), y);
        _movementState = sMovingRight;

    } else {
        _x = area.right();
        _position.set(_area.right(), y);
        _velocity *= -1.0;
        _movementState = sMovingLeft;
    }

    _animation.push_back(&_animationA);
    _animation.push_back(&_animationB);
    _animation.push_back(&_animationC);
    _animation.push_back(&_animationB);
    _animationIndex = _animation.begin();

}


//-----------------------------------------------------------------------------
DemonBat::~DemonBat()
{

}


//-----------------------------------------------------------------------------
Rect DemonBat::boundingRect() const
{
    return Rect::centerAroundPoint(_position, 6, 3);
}


//-----------------------------------------------------------------------------
void DemonBat::update()
{
    if (_state == sActive) {

        // Movement
        double time = _movementTimer.elapsed();

        _x += (_velocity * time);
        _position.setX(_x);
            
        if (!_area.contains(_position)) {
            _state = sEscaped;
        }

        _movementTimer.reset();


        // Animation timer
        if (_animationTimer.elapsed() > 0.200) {
            ++_animationIndex;
            if (_animationIndex == _animation.end()) {
                _animationIndex = _animation.begin();
            }

            _animationTimer.reset();
        }
    }
}


//-----------------------------------------------------------------------------
void DemonBat::render(Canvas& canvas)
{
    
    Bitmap* bitmap(*_animationIndex);
    Rect rect(Rect::centerAroundPoint(_position, bitmap->width(), bitmap->height()));
    canvas.drawBitmap(*bitmap, rect.x(), rect.y());
}


//-----------------------------------------------------------------------------
std::list<Particle*> DemonBat::spawnParticles()
{
    std::list<Particle*> particles;


    // Add velocity based on how dead the bat is
    double effectVelocity = (_health * -1) * 0.1;

    // Spawn particles
    double velocity;
    velocity = ((double)(rand() % 100) / 100.0) * 0.8 + effectVelocity;
    Particle* particle = new Particle(_position.x(), _position.y(), randomAngle(90, 40), velocity, Element('@', COLOR_RED), Rect(0,0, 80, 25));
    particles.push_back(particle);

    velocity = ((double)(rand() % 100) / 100.0) * 0.8 + effectVelocity;
    particle = new Particle(_position.x(), _position.y(), randomAngle(90, 40), velocity, Element('@', COLOR_RED), Rect(0,0, 80, 25));
    particles.push_back(particle);

    velocity = ((double)(rand() % 100) / 100.0) * 0.8 + effectVelocity;
    particle = new Particle(_position.x(), _position.y(), randomAngle(90, 40), velocity, Element('@', COLOR_RED), Rect(0,0, 80, 25));
    particles.push_back(particle);

    velocity = ((double)(rand() % 100) / 100.0) * 0.8 + 0.2 + effectVelocity;
    particle = new Particle(_position.x() - 1, _position.y(), randomAngle(135, 20), velocity, Element('\\', COLOR_RED), Rect(0,0, 80, 25));
    particles.push_back(particle);


    velocity = ((double)(rand() % 100) / 100.0) * 0.8 + 0.2 + effectVelocity;
    particle = new Particle(_position.x() + 1, _position.y(), randomAngle(45, 20), velocity, Element('/', COLOR_RED), Rect(0,0, 80, 25));
    particles.push_back(particle);

    return particles;
}


//-----------------------------------------------------------------------------
double DemonBat::randomAngle(double initial, double deviation)
{
    // Random deviation
    double randomDeviation = ((rand() % 100) / 100.0) * deviation;
    if ((rand() % 100) > 50) {
        randomDeviation *= -1;
    }

    // Scale
    double radians = (((initial + randomDeviation) * (2.0 * 3.141)) / 360.0);

    return -radians;

}
