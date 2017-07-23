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

#ifndef __GRENADE_H__
#define __GRENADE_H__

#include "bullet.h"


class Grenade : public Bullet
{

public:
	Grenade(
		int x,
		int y,
		double angle,
		double velocity,
		int damage,
		const Rect& activeRect,
		const Element& element);
	~Grenade();
	void update();


	bool hasRadiusDamage() const { return true; }
	double damageRadius() const { return 10*10; }
	std::list<Particle*> spawnResidue() const;

private:
	double _x;
	double _y;
	double _velocityX;
	double _velocityY;
	double _gravity;
	double _velocity;
	double _angle;
};

#endif
