/*
	Copyright (c) 2017 Willem Kemp (https://github.com/wjkemp)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include "itemdrop.h"
#include "graphics/images.h"
#include "utilities/random.h"
#include <math.h>


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

ItemDrop::~ItemDrop()
{

}

Modifier ItemDrop::modifier() const
{

	return _modifier;
}

Rect ItemDrop::boundingRect() const
{
	return Rect::centerAroundPoint(_position, 1, 1);
}

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

void ItemDrop::render(Canvas& canvas)
{
	if (_state != sExpired) {
		canvas.drawElement(_element, _position.x(), _position.y());
	}
}
