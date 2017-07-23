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

#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "bitmap.h"
#include "element.h"
#include "colors.h"


class Canvas
{

public:
	Canvas(int width, int height);
	~Canvas();
	void clear();
	int width() const   { return _width; }
	int height() const  { return _height; }

	void drawBitmap(const Bitmap& bitmap, int x, int y);
	void drawElement(const Element& element, int x, int y);
	void drawText(const char* text, int x, int y, Color color);
	void drawRtlText(const char* text, int x, int y, Color color);

	unsigned long* buffer() { return _buffer; }

private:
	int _width;
	int _height;
	unsigned long* _buffer;
};

#endif
