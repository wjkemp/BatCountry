/*  worldobject.h
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
#ifndef __WORLDOBJECT_H__
#define __WORLDOBJECT_H__

#include "utilities/point.h"
#include "utilities/rect.h"
#include "graphics/canvas.h"
#include <list>



//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class WorldObject
{

public:
    WorldObject(int x, int y);
    virtual ~WorldObject();
    virtual Rect boundingRect() const = 0;
    virtual void update() = 0;
    virtual void render(Canvas& canvas) = 0;

    Point position() const { return _position; }

protected:
    Point _position;

};



#endif
