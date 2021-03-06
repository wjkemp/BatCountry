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

#ifndef __BAT_H__
#define __BAT_H__

#include "enemy.h"


class Bat : public Enemy
{
public:
	enum AnimationState
	{
		sAnimateA,
		sAnimateB
	};

	enum MovementState
	{
		sMovingLeft,
		sMovingRight
	};

public:
	Bat(const Rect& area, double velocityBase);
	~Bat();

	Rect boundingRect() const;
	void update();
	void render(Canvas& canvas);
	std::list<Particle*> spawnParticles();
	int reward() const { return 10; }

private:
	Rect _area;
	double _x;
	double _velocityVariation;
	double _velocity;
	AnimationState _animationState;
	MovementState _movementState;
	Bitmap _animationA;
	Bitmap _animationB;
	Timer _animationTimer;
	Timer _movementTimer;
};

#endif
