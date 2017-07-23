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

#include "demonbat.h"
#include "graphics/images.h"
#include "utilities/random.h"


DemonBat::DemonBat(const Rect& area, double velocityBase) :
	Enemy(6),
	_area(area),
	_velocityVariation(4),
	_movementState(sMovingRight),
	_animationA(IMG_DEMONBAT_A),
	_animationB(IMG_DEMONBAT_B),
	_animationC(IMG_DEMONBAT_C),
	_animationTimer("demonbat_animation_timer"),
	_movementTimer("demonbat_movement_timer")
{

	// Random height
	int y = _area.top() + Random::random(_area.height());

	// Velociry
	_velocity = velocityBase + (Random::random() * _velocityVariation);

	// Start from an edge
	if (Random::choice()) {
		_x = area.left();
		_position.set(_area.left(), y);
		_movementState = sMovingRight;

	} else {
		_x = area.right();
		_position.set(_area.right(), y);
		_velocity *= -1.0;
		_movementState = sMovingLeft;
	}

	_animation.push_back(&_animationA);
	_animation.push_back(&_animationB);
	_animation.push_back(&_animationC);
	_animation.push_back(&_animationB);
	_animationIndex = _animation.begin();
}

DemonBat::~DemonBat()
{

}

Rect DemonBat::boundingRect() const
{
	return Rect::centerAroundPoint(_position, 6, 3);
}

void DemonBat::update()
{
	if (_state == sActive) {

		// Movement
		double time = _movementTimer.elapsed();

		_x += (_velocity * time);
		_position.setX(_x);

		if (!_area.contains(_position)) {
			_state = sEscaped;
		}

		_movementTimer.reset();


		// Animation timer
		if (_animationTimer.elapsed() > 0.200) {
			++_animationIndex;
			if (_animationIndex == _animation.end()) {
				_animationIndex = _animation.begin();
			}

			_animationTimer.reset();
		}
	}
}

void DemonBat::render(Canvas& canvas)
{

	Bitmap* bitmap(*_animationIndex);
	Rect rect(Rect::centerAroundPoint(_position, bitmap->width(), bitmap->height()));
	canvas.drawBitmap(*bitmap, rect.x(), rect.y());
}

std::list<Particle*> DemonBat::spawnParticles()
{
	std::list<Particle*> particles;

	// Add velocity based on how dead the bat is
	double effectVelocity = (_health * -1) * 0.1;

	// Spawn particles
	double velocity;
	velocity = (Random::random() * 0.8) + effectVelocity;
	Particle* particle = new Particle(_position.x(), _position.y(), Random::randomAngle(90, 40), velocity, Element('@', COLOR_RED), Rect(0,0, 80, 25));
	particles.push_back(particle);

	velocity = (Random::random() * 0.8) + effectVelocity;
	particle = new Particle(_position.x(), _position.y(), Random::randomAngle(90, 40), velocity, Element('@', COLOR_RED), Rect(0,0, 80, 25));
	particles.push_back(particle);

	velocity = (Random::random() * 0.8) + effectVelocity;
	particle = new Particle(_position.x(), _position.y(), Random::randomAngle(90, 40), velocity, Element('@', COLOR_RED), Rect(0,0, 80, 25));
	particles.push_back(particle);

	velocity = (Random::random() * 0.8) + 0.2 + effectVelocity;
	particle = new Particle(_position.x() - 1, _position.y(), Random::randomAngle(135, 20), velocity, Element('\\', COLOR_RED), Rect(0,0, 80, 25));
	particles.push_back(particle);


	velocity = (Random::random() * 0.8) + 0.2 + effectVelocity;
	particle = new Particle(_position.x() + 1, _position.y(), Random::randomAngle(45, 20), velocity, Element('/', COLOR_RED), Rect(0,0, 80, 25));
	particles.push_back(particle);

	return particles;
}
