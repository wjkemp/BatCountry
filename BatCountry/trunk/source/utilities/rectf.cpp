/*  rectf.cpp
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
#include "rectf.h"


//-----------------------------------------------------------------------------
RectF::RectF() :
    _x(0.0),
    _y(0.0),
    _width(0.0),
    _height(0.0)
{

}


//-----------------------------------------------------------------------------
RectF::RectF(const RectF& obj) :
    _x(obj._x),
    _y(obj._y),
    _width(obj._width),
    _height(obj._height)
{

}


//-----------------------------------------------------------------------------
RectF::RectF(double x, double y, double width, double height) :
    _x(x),
    _y(y),
    _width(width),
    _height(height)
{

}


//-----------------------------------------------------------------------------
bool RectF::contains(const PointF& point) const
{
    return (
        (point.x() >= _x) && 
        (point.y() >= _y) && 
        (point.x() < (_x + _width)) &&
        (point.y() < (_y + _height)));

}


//-----------------------------------------------------------------------------
RectF RectF::centerAroundPoint(const PointF& point, double width, double height)
{
    return RectF(point.x() - (width / 2), point.y() - (height / 2), width, height);
}
