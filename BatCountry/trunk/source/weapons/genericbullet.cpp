/*  genericbullet.cpp
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
#include "genericbullet.h"


//-----------------------------------------------------------------------------
GenericBullet::GenericBullet(
    double x,
    double y,
    double directionX,
    double directionY,
    int damage,
    double velocity,
    bool penetrating,
    const Rect& activeRect,
    const Element& element) :
    Bullet(x, y, damage, activeRect, element),
    _x0(x),
    _y0(y),
    _directionX(directionX),
    _directionY(directionY),
    _velocity(velocity),
    _penetrating(penetrating)
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

        _x0 = _x;
        _y0 = _y;

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
bool GenericBullet::isPenetrating() const
{
    return _penetrating;
}


//-----------------------------------------------------------------------------
bool GenericBullet::intersects(const Rect& rect) const
{
    bool result = false;

    result |= intersects((int)(_x0 + 0.5), (int)(_y0 + 0.5), (int)(_x + 0.5), (int)(_y + 0.5), rect.left(), rect.top(), rect.right(), rect.top());
    result |= intersects((int)(_x0 + 0.5), (int)(_y0 + 0.5),(int)(_x + 0.5), (int)(_y + 0.5), rect.left(), rect.bottom(), rect.right(), rect.bottom());
    result |= intersects((int)(_x0 + 0.5), (int)(_y0 + 0.5), (int)(_x + 0.5), (int)(_y + 0.5), rect.left(), rect.top(), rect.left(), rect.bottom());
    result |= intersects((int)(_x0 + 0.5), (int)(_y0 + 0.5), (int)(_x + 0.5), (int)(_y + 0.5), rect.right(), rect.top(), rect.right(), rect.bottom());

    return result;
}


//-----------------------------------------------------------------------------
bool GenericBullet::intersects(double Ax, double Ay, double Bx, double By, double Cx, double Cy, double Dx, double Dy) const
{
    bool result = false;

    double numerator0 = (((Ay - Cy) * (Dx - Cx)) - ((Ax - Cx) * (Dy - Cy)));
    double numerator1 = ((Ay - Cy) * (Bx - Ax) - ((Ax - Cx) * (By - Ay)));
    double denominator = (((Bx - Ax) * (Dy - Cy)) - ((By - Ay) * (Dx - Cx)));

    if ((denominator != 0)) {
        double r =  numerator0 / denominator;
        double s = numerator1 / denominator;

        if (!(r < 0.0 || r > 1.0) && !(s < 0.0 || s > 1.0)) {
            result = true;
        }
    }

    return result;
}
