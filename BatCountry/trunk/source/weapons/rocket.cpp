/******************************************************************************
    rocket.cpp
 ******************************************************************************/
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
