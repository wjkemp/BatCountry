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

#include "genericbullet.h"


GenericBullet::GenericBullet(
	double x,
	double y,
	double directionX,
	double directionY,
	int damage,
	double velocity,
	bool penetrating,
	const Rect& activeRect,
	const Element& element) :
	Bullet(x, y, damage, activeRect, element),
	_x0(x),
	_y0(y),
	_directionX(directionX),
	_directionY(directionY),
	_velocity(velocity),
	_penetrating(penetrating)
{

}

GenericBullet::~GenericBullet()
{

}

void GenericBullet::update()
{
	if (_state == sActive) {

		double time = _updateTimer.elapsed();

		_x0 = _x;
		_y0 = _y;

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

bool GenericBullet::isPenetrating() const
{
	return _penetrating;
}

bool GenericBullet::intersects(const Rect& rect) const
{
	bool result = false;

	result |= intersects((int)(_x0 + 0.5), (int)(_y0 + 0.5), (int)(_x + 0.5), (int)(_y + 0.5), rect.left(), rect.top(), rect.right(), rect.top());
	result |= intersects((int)(_x0 + 0.5), (int)(_y0 + 0.5),(int)(_x + 0.5), (int)(_y + 0.5), rect.left(), rect.bottom(), rect.right(), rect.bottom());
	result |= intersects((int)(_x0 + 0.5), (int)(_y0 + 0.5), (int)(_x + 0.5), (int)(_y + 0.5), rect.left(), rect.top(), rect.left(), rect.bottom());
	result |= intersects((int)(_x0 + 0.5), (int)(_y0 + 0.5), (int)(_x + 0.5), (int)(_y + 0.5), rect.right(), rect.top(), rect.right(), rect.bottom());

	return result;
}

bool GenericBullet::intersects(double Ax, double Ay, double Bx, double By, double Cx, double Cy, double Dx, double Dy) const
{
	bool result = false;

	double numerator0 = (((Ay - Cy) * (Dx - Cx)) - ((Ax - Cx) * (Dy - Cy)));
	double numerator1 = ((Ay - Cy) * (Bx - Ax) - ((Ax - Cx) * (By - Ay)));
	double denominator = (((Bx - Ax) * (Dy - Cy)) - ((By - Ay) * (Dx - Cx)));

	if ((denominator != 0)) {
		double r =  numerator0 / denominator;
		double s = numerator1 / denominator;

		if (!(r < 0.0 || r > 1.0) && !(s < 0.0 || s > 1.0)) {
			result = true;
		}
	}

	return result;
}
