/******************************************************************************
    rect.cpp
 ******************************************************************************/
#include "rect.h"


//-----------------------------------------------------------------------------
Rect::Rect() :
    _x(0),
    _y(0),
    _width(0),
    _height(0)
{

}


//-----------------------------------------------------------------------------
Rect::Rect(const Rect& obj) :
    _x(obj._x),
    _y(obj._y),
    _width(obj._width),
    _height(obj._height)
{

}


//-----------------------------------------------------------------------------
Rect::Rect(int x, int y, int width, int height) :
    _x(x),
    _y(y),
    _width(width),
    _height(height)
{

}


//-----------------------------------------------------------------------------
bool Rect::contains(const Point& point) const
{
    return (
        (point.x() >= _x) && 
        (point.y() >= _y) && 
        (point.x() < (_x + _width)) &&
        (point.y() < (_y + _height)));

}


//-----------------------------------------------------------------------------
Rect Rect::centerAroundPoint(const Point& point, int width, int height)
{
    return Rect(point.x() - (width / 2), point.y() - (height / 2), width, height);
}
