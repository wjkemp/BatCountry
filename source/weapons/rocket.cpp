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

#include "rocket.h"
#include "utilities/random.h"


Rocket::Rocket(
	double x,
	double y,
	double directionX,
	double directionY,
	int damage,
	double velocity,
	const Rect& activeRect,
	const Element& element) :
	Bullet(x, y, damage, activeRect, element),
	_x(x),
	_y(y),
	_directionX(directionX),
	_directionY(directionY),
	_velocity(velocity)
{

}

Rocket::~Rocket()
{

}

void Rocket::update()
{
	if (_state == sActive) {

		double time = _updateTimer.elapsed();

		_x += _directionX * _velocity * time;
		_y += _directionY * _velocity * time;
		_position.setX(_x);
		_position.setY(_y);

		if (!_activeRect.contains(_position)) {
			_state = sExpired;
		}

		_updateTimer.reset();
	}
}

std::list<Particle*> Rocket::spawnResidue() const
{
	std::list<Particle*> particles;

	// High Base Velocity
	double effectVelocity = 2.0;

	// Spawn particles
	for (int i=0; i < 10; ++i) {
		double velocity;
		velocity = (Random::random() * 0.8) + effectVelocity;
		Particle* particle = new Particle(_position.x(), _position.y(), Random::randomAngle(90, 120), velocity, Element('.', COLOR_WHITE), Rect::centerAroundPoint(_position, 16, 16));
		particles.push_back(particle);
	}

	return particles;
}
