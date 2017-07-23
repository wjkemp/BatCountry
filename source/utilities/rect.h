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

#ifndef __RECT_H__
#define __RECT_H__


#include "point.h"


class Rect
{

public:
	Rect();
	Rect(const Rect& obj);
	Rect(int x, int y, int width, int height);
	int x() const { return _x; }
	int y() const { return _y; }
	int width() const { return _width; }
	int height() const { return _height; }
	int left() const { return _x; }
	int top() const { return _y; }
	int right() const { return _x + _width - 1; }
	int bottom() const { return _y + _height - 1; }

	bool contains(const Point& point) const;

	static Rect centerAroundPoint(const Point& point, int width, int height);

private:
	int _x;
	int _y;
	int _width;
	int _height;
};

#endif
