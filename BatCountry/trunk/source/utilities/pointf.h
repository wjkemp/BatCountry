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
#ifndef __POINTF_H__
#define __POINTF_H__

#include <math.h>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class PointF
{

public:
    PointF();
    PointF(const PointF& obj);
    PointF(double x, double y);
    double x() const { return _x; }
    double y() const { return _y; }

    void set(double x, double y) { _x = x; _y = y; }
    void setX(double x) { _x = x; }
    void setY(double y) { _y = y; }

    double distanceTo(const PointF& point) const;

private:
    double _x;
    double _y;
    
};



#endif
