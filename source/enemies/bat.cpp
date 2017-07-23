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

#include "bat.h"
#include "graphics/images.h"
#include "utilities/random.h"


Bat::Bat(const Rect& area, double velocityBase) :
	Enemy(2),
	_area(area),
	_velocityVariation(4),
	_animationState(sAnimateA),
	_movementState(sMovingRight),
	_animationA(IMG_BAT_A),
	_animationB(IMG_BAT_B),
	_animationTimer("bat_animation_timer"),
	_movementTimer("bat_movement_timer")
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

}

Bat::~Bat()
{

}

Rect Bat::boundingRect() const
{
	return Rect::centerAroundPoint(_position, 3, 1);
}

void Bat::update()
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
		if (_animationTimer.elapsed() > 0.400) {
			switch (_animationState) {
				case sAnimateA: {
					_animationState = sAnimateB;
				} break;

				case sAnimateB: {
					_animationState = sAnimateA;
				} break;
			}

			_animationTimer.reset();
		}
	}
}

void Bat::render(Canvas& canvas)
{

	switch (_animationState) {
		case sAnimateA: {
			Rect rect(Rect::centerAroundPoint(_position, _animationA.width(), _animationA.height()));
			canvas.drawBitmap(_animationA, rect.x(), rect.y());
		} break;

		case sAnimateB: {
			Rect rect(Rect::centerAroundPoint(_position, _animationB.width(), _animationB.height()));
			canvas.drawBitmap(_animationB, rect.x(), rect.y());
		} break;
	}
}

std::list<Particle*> Bat::spawnParticles()
{
	std::list<Particle*> particles;


	// Add velocity based on how dead the bat is
	double effectVelocity = (_health * -1) * 0.2;

	// Spawn particles
	double velocity;
	velocity = (Random::random() * 0.8) + effectVelocity;
	Particle* particle = new Particle(_position.x(), _position.y(), Random::randomAngle(90, 20), velocity, Element('o', COLOR_RED), Rect(0,0, 80, 25));
	particles.push_back(particle);

	velocity = (Random::random() * 0.8) + 0.2 + effectVelocity;
	particle = new Particle(_position.x() - 1, _position.y(), Random::randomAngle(135, 20), velocity, Element('>', COLOR_RED), Rect(0,0, 80, 25));
	particles.push_back(particle);


	velocity = (Random::random() * 0.8) + 0.2 + effectVelocity;
	particle = new Particle(_position.x() + 1, _position.y(), Random::randomAngle(45, 20), velocity, Element('<', COLOR_RED), Rect(0,0, 80, 25));
	particles.push_back(particle);

	return particles;
}
