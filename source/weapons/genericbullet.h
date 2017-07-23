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

#ifndef __GENERICBULLET_H__
#define __GENERICBULLET_H__

#include "bullet.h"


class GenericBullet : public Bullet
{

public:
	GenericBullet(
		double x,
		double y,
		double directionX,
		double directionY,
		int damage,
		double velocity,
		bool penetrating,
		const Rect& activeRect,
		const Element& element);
	~GenericBullet();

	void update();
	bool isPenetrating() const;
	bool intersects(const Rect& rect) const;

protected:
	bool intersects(double Ax, double Ay, double Bx, double By, double Cx, double Cy, double Dx, double Dy) const;

private:
	double _x0;
	double _y0;
	double _directionX;
	double _directionY;
	double _velocity;
	bool _penetrating;
};

#endif
