/******************************************************************************
    rect.h
 ******************************************************************************/
#ifndef __RECT_H__
#define __RECT_H__


#include "point.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Rect
{

public:
    Rect();
    Rect(const Rect& obj);
    Rect(int x, int y, int width, int height);
    int x() const { return _x; }
    int y() const { return _y; }
    int width() const { return _width; }
    int height() const { return _height; }
    int left() const { return _x; }
    int top() const { return _y; }
    int right() const { return _x + _width - 1; }
    int bottom() const { return _y + _height - 1; }

    bool contains(const Point& point) const;

    static Rect centerAroundPoint(const Point& point, int width, int height);

private:
    int _x;
    int _y;
    int _width;
    int _height;
};



#endif
