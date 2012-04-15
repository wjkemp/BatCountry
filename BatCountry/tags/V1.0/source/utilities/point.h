/*  point.h
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
