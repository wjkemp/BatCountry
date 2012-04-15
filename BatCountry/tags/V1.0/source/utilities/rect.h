/*  rect.h
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
