/******************************************************************************
    genericbullet.cpp
 ******************************************************************************/
#include "genericbullet.h"


//-----------------------------------------------------------------------------
GenericBullet::GenericBullet(
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
GenericBullet::~GenericBullet()
{

}


//-----------------------------------------------------------------------------
void GenericBullet::update()
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

