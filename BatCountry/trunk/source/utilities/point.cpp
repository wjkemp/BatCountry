/******************************************************************************
    point.cpp
 ******************************************************************************/
#include "point.h"


//-----------------------------------------------------------------------------
Point::Point() :
    _x(0),
    _y(0)
{

}


//-----------------------------------------------------------------------------
Point::Point(const Point& obj) :
    _x(obj._x),
    _y(obj._y)
{

}


//-----------------------------------------------------------------------------
Point::Point(int x, int y) :
    _x(x),
    _y(y)
{

}


//-----------------------------------------------------------------------------
double Point::distanceTo(const Point& point) const
{
    return ((_x - point.x())*(_x - point.x()) + (_y - point.y())*(_y - point.y()));
}