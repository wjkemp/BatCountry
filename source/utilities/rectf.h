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

#ifndef __RECTF_H__
#define __RECTF_H__


#include "pointf.h"


class RectF
{

public:
	RectF();
	RectF(const RectF& obj);
	RectF(double x, double y, double width, double height);
	double x() const { return _x; }
	double y() const { return _y; }
	double width() const { return _width; }
	double height() const { return _height; }
	double left() const { return _x; }
	double top() const { return _y; }
	double right() const { return _x + _width - 1.0; }
	double bottom() const { return _y + _height - 1.0; }

	bool contains(const PointF& point) const;

	static RectF centerAroundPoint(const PointF& point, double width, double height);

private:
	double _x;
	double _y;
	double _width;
	double _height;
};

#endif
