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

#include "particle.h"
#include "graphics/images.h"
#include <math.h>


Particle::Particle(int x, int y, double angle, double velocity, const Element& element, const Rect& worldRect) :
	WorldObject(x, y),
	_state(sActive),
	_worldRect(worldRect),
	_element(element),
	_updateTimer("particle_update_timer"),
	_activeTimer("particle_active_timer")
{

	_x = x;
	_y = y;
	_velocity = velocity;
	_gravity = 0.1;
	_angle = angle;

	_velocityX = _velocity * cos(_angle);
	_velocityY = _velocity * sin(_angle);

}

Particle::~Particle()
{

}

Rect Particle::boundingRect() const
{
	return Rect::centerAroundPoint(_position, 1, 1);
}

void Particle::update()
{
	if (_state == sActive) {

		if (_updateTimer.elapsed() > 0.050) {


			 _x += _velocityX;
			 _y += _velocityY;

			 // update velocity
			 _velocityY += _gravity;

			_position.setX(_x);
			_position.setY(_y);
			if (!_worldRect.contains(_position)) {
				_state = sExpired;
			}

			_updateTimer.reset();
		}

		if (_activeTimer.elapsed() > 0.800) {
			_state = sExpired;
		}
	}
}

void Particle::render(Canvas& canvas)
{
	canvas.drawElement(_element, _position.x(), _position.y());
}
