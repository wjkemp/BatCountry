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

#ifndef __POINT_H__
#define __POINT_H__

#include <math.h>


class Point
{

public:
	Point();
	Point(const Point& obj);
	Point(int x, int y);
	int x() const { return _x; }
	int y() const { return _y; }

	void set(int x, int y) { _x = x; _y = y; }
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

	void set(double x, double y) { _x = (int)(x + 0.5); _y = (int)(y + 0.5); }
	void setX(double x) { _x = _x = (int)(x + 0.5); }
	void setY(double y) { _y = _y = (int)(y + 0.5); }

	double distanceTo(const Point& point) const;

private:
	int _x;
	int _y;
};

#endif
