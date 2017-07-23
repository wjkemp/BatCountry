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

#include "actor.h"
#include "graphics/images.h"
#include "utilities/random.h"


Actor::Actor(ModifierManager* modifiers, const Rect& area, unsigned long& keystate) :
	WorldObject(40, 33),
	_modifiers(modifiers),
	_area(area),
	_image(IMG_ACTOR),
	_movementTimer("actor_movement"),
	_keystate(keystate)
{
}

Actor::~Actor()
{

}

Rect Actor::boundingRect() const
{
	return Rect::centerAroundPoint(_position, 1, 1);
}

void Actor::update()
{
	double movementSpeed = (_modifiers->isModifierActive(Modifier::mBoost) ? 0.025 : 0.050);

	if (_movementTimer.elapsed() > movementSpeed) {

		if ((_keystate & KEYSTATE_LEFT) && (_position.x() > _area.left())) {
			_position.setX(_position.x() - 1);
		}

		if ((_keystate & KEYSTATE_RIGHT) && (_position.x() < (_area.left() + _area.width() - 1))) {
			_position.setX(_position.x() + 1);
		}

		_movementTimer.reset();
	}
}

void Actor::render(Canvas& canvas)
{
	Rect rect(Rect::centerAroundPoint(_position, _image.width(), _image.height()));
	canvas.drawBitmap(_image, rect.x(), rect.y());
}
