/*  itemdrop.cpp
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
#include "itemdrop.h"
#include "graphics/images.h"
#include "utilities/random.h"
#include <math.h>


//-----------------------------------------------------------------------------
ItemDrop::ItemDrop(int x, int y, double angle, double velocity, const Modifier& modifier, const Element& element, const Rect& worldRect) :
    WorldObject(x, y),
    _state(sDropping),
    _modifier(modifier),
    _element(element),
    _worldRect(worldRect),
    _updateTimer("itemdrop_update_timer"),
    _activeTimer("itemdrop_active_timer")
{

    _x = x;
    _y = y;
    _velocity = velocity;
    _gravity = 0.1;
    _angle = angle;

    _velocityX = _velocity * cos(_angle);
    _velocityY = _velocity * sin(_angle);

}


//-----------------------------------------------------------------------------
ItemDrop::~ItemDrop()
{

}


//-----------------------------------------------------------------------------
Modifier ItemDrop::modifier() const
{

    return _modifier;
}


//-----------------------------------------------------------------------------
Rect ItemDrop::boundingRect() const
{
    return Rect::centerAroundPoint(_position, 1, 1);
}


//-----------------------------------------------------------------------------
void ItemDrop::update()
{
    if (_state == sDropping) {
    
        if (_updateTimer.elapsed() > 0.050) {

            _x += _velocityX;
            _y += _velocityY;

            // update velocity
            _velocityY += _gravity;

            _position.setX(_x);
            _position.setY(_y);

            if (_position.y() >= _worldRect.bottom()) {
                _position.setY(_worldRect.bottom());
                _state = sStationary;
                _activeTimer.reset();
            }

            _updateTimer.reset();
        }

    } else if (_state == sStationary) {
        if (_activeTimer.elapsed() > 5.0) {
            _state = sExpired;
        }
    }
}


//-----------------------------------------------------------------------------
void ItemDrop::render(Canvas& canvas)
{
    if (_state != sExpired) {
        canvas.drawElement(_element, _position.x(), _position.y());    
    }
}
