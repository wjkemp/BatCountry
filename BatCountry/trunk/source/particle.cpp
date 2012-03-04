/******************************************************************************
    particle.cpp
 ******************************************************************************/
#include "particle.h"
#include "graphics/images.h"
#include <math.h>


//-----------------------------------------------------------------------------
Particle::Particle(int x, int y, double angle, double velocity, const Element& element, const Rect& worldRect) :
    WorldObject(x, y),
    _state(sActive),
    _worldRect(worldRect),
    _element(element)
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
