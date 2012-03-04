/******************************************************************************
    point.h
 ******************************************************************************/
#ifndef __POINT_H__
#define __POINT_H__

#include <math.h>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Point
{

public:
    Point();
    Point(const Point& obj);
    Point(int x, int y);
    int x() const { return _x; }
    int y() const { return _y; }

    void set(int x, int y) { _x = x; _y = y; }
    void setX(int x) { _x = x; }
    void setY(int y) { _y = y; }

    void set(double x, double y) { _x = (int)(x + 0.5); _y = (int)(y + 0.5); }
    void setX(double x) { _x = _x = (int)(x + 0.5); }
    void setY(double y) { _y = _y = (int)(y + 0.5); }

    double distanceTo(const Point& point) const;

private:
    int _x;
    int _y;
    
};



#endif
