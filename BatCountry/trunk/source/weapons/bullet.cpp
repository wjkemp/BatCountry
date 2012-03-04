/******************************************************************************
    bullet.cpp
 ******************************************************************************/
#include "bullet.h"


//-----------------------------------------------------------------------------
Bullet::Bullet(double x, double y, int damage, const Rect& activeRect, const Element& element) :
    WorldObject((int)x, (int)y),
    _state(sActive),
    _damage(damage),
    _activeRect(activeRect),
    _element(element)
{

}


//-----------------------------------------------------------------------------
Bullet::~Bullet()
{

}


//-----------------------------------------------------------------------------
Rect Bullet::boundingRect() const
{
    return Rect::centerAroundPoint(_position, 1, 1);
}


//-----------------------------------------------------------------------------
void Bullet::render(Canvas& canvas)
{
    canvas.drawElement(_element, _position.x(), _position.y());
}


//-----------------------------------------------------------------------------
bool Bullet::hasRadiusDamage() const
{
    return false;
}


//-----------------------------------------------------------------------------
double Bullet::damageRadius() const
{
    return 0.0;
}


//-----------------------------------------------------------------------------
std::list<Particle*> Bullet::spawnResidue() const
{
    return std::list<Particle*>();
}
