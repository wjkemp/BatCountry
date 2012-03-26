/*  actor.cpp
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
#include "actor.h"
#include "graphics/images.h"
#include "utilities/random.h"


//-----------------------------------------------------------------------------
Actor::Actor(const Rect& area, unsigned long& keystate) :
    WorldObject(40, 18),
    _area(area),
    _image(IMG_ACTOR),
    _movementTimer("actor_movement"),
    _keystate(keystate)
{
}


//-----------------------------------------------------------------------------
Actor::~Actor()
{

}



//-----------------------------------------------------------------------------
Rect Actor::boundingRect() const
{
    return Rect::centerAroundPoint(_position, 1, 1);
}


//-----------------------------------------------------------------------------
void Actor::update()
{

    if (_movementTimer.elapsed() > 0.050) {

        if ((_keystate & KEYSTATE_LEFT) && (_position.x() > _area.left())) {
            _position.setX(_position.x() - 1);
        }

        if ((_keystate & KEYSTATE_RIGHT) && (_position.x() < (_area.left() + _area.width() - 1))) {
            _position.setX(_position.x() + 1);
        }

        _movementTimer.reset();
    }
}


//-----------------------------------------------------------------------------
void Actor::render(Canvas& canvas)
{
    Rect rect(Rect::centerAroundPoint(_position, _image.width(), _image.height()));
    canvas.drawBitmap(_image, rect.x(), rect.y());

    
}
