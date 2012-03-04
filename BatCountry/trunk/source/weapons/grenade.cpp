/******************************************************************************
    grenade.cpp
 ******************************************************************************/
#include "grenade.h"
#include "utilities/random.h"


//-----------------------------------------------------------------------------
Grenade::Grenade(
    int x,
    int y,
    double angle,
    double velocity,
    int damage,
    const Rect& activeRect,
    const Element& element) :
    Bullet(x, y, damage, activeRect, element),
    _x(x),
    _y(y),
    _velocity(velocity)
{

    _gravity = 60;
    _angle = angle;

    _velocityX = _velocity * cos(_angle);
    _velocityY = _velocity * sin(_angle);
}


//-----------------------------------------------------------------------------
Grenade::~Grenade()
{

}


//-----------------------------------------------------------------------------
void Grenade::update()
{
    if (_state == sActive) {
    
        double time = _updateTimer.elapsed();

        _x += _velocityX * time;
        _y += _velocityY * time;

         // update velocity
         _velocityY += (_gravity * time);

        _position.setX(_x);
        _position.setY(_y);
        if (!_activeRect.contains(_position)) {
            _state = sExpired;
        }
            
        if (!_activeRect.contains(_position)) {
            _state = sExpired;
        }

        _updateTimer.reset();
    }
}


//-----------------------------------------------------------------------------
std::list<Particle*> Grenade::spawnResidue() const
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
