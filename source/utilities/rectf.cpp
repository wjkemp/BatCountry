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

#include "rectf.h"


RectF::RectF() :
	_x(0.0),
	_y(0.0),
	_width(0.0),
	_height(0.0)
{

}

RectF::RectF(const RectF& obj) :
	_x(obj._x),
	_y(obj._y),
	_width(obj._width),
	_height(obj._height)
{

}

RectF::RectF(double x, double y, double width, double height) :
	_x(x),
	_y(y),
	_width(width),
	_height(height)
{

}

bool RectF::contains(const PointF& point) const
{
	return (
		(point.x() >= _x) &&
		(point.y() >= _y) &&
		(point.x() < (_x + _width)) &&
		(point.y() < (_y + _height)));
}

RectF RectF::centerAroundPoint(const PointF& point, double width, double height)
{
	return RectF(point.x() - (width / 2), point.y() - (height / 2), width, height);
}
