/*  rectf.h
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
#ifndef __RECTF_H__
#define __RECTF_H__


#include "pointf.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class RectF
{

public:
    RectF();
    RectF(const RectF& obj);
    RectF(double x, double y, double width, double height);
    double x() const { return _x; }
    double y() const { return _y; }
    double width() const { return _width; }
    double height() const { return _height; }
    double left() const { return _x; }
    double top() const { return _y; }
    double right() const { return _x + _width - 1.0; }
    double bottom() const { return _y + _height - 1.0; }

    bool contains(const PointF& point) const;

    static RectF centerAroundPoint(const PointF& point, double width, double height);

private:
    double _x;
    double _y;
    double _width;
    double _height;
};



#endif
