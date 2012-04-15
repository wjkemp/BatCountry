/*  bullet.cpp
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
#include "bullet.h"


//-----------------------------------------------------------------------------
Bullet::Bullet(double x, double y, int damage, const Rect& activeRect, const Element& element) :
    WorldObject((int)x, (int)y),
    _x(x),
    _y(y),
    _state(sActive),
    _damage(damage),
    _activeRect(activeRect),
    _element(element),
    _updateTimer("bullet_update_timer")
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


//-----------------------------------------------------------------------------
bool Bullet::intersects(const Rect& rect) const
{
    return false;
}

