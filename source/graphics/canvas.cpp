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

#include "canvas.h"
#include <string.h>


Canvas::Canvas(int width, int height) :
	_width(width),
	_height(height)
{
	_buffer = new unsigned long[_width * _height];
}

Canvas::~Canvas()
{
	delete [] _buffer;
}

void Canvas::clear()
{
	memset(_buffer, 0, _width * _height * sizeof(unsigned long));
}

void Canvas::drawBitmap(const Bitmap& bitmap, int x, int y)
{
	unsigned long* src = bitmap.buffer();
	unsigned long* dest = _buffer;

	for (int w = 0; w < bitmap.width(); ++w) {
		for (int h = 0; h < bitmap.height(); ++h) {
			int dx = x + w;
			int dy = y + h;
			if ((dx < _width) && (dy < _height) && (dx >= 0) && (dy >= 0)) {
				if (src[w + (h * bitmap.width())]) {
					dest[dx + (dy * _width)] = src[w + (h * bitmap.width())];
				}
			}
		}
	}
}

void Canvas::drawElement(const Element& element, int x, int y)
{
	unsigned long* dest = _buffer;
	if ((x < _width) && (y < _height) && (x >= 0) && (y >= 0)) {
		dest[x + (y * _width)] = element.raw();
	}
}

void Canvas::drawText(const char* text, int x, int y, Color color)
{
	while (*text) {
		if ((x < _width) && (y < _height) && (x >= 0) && (y >= 0)) {
			_buffer[x + (y * _width)] = *text | (color << 8);
		}
		text++;
		x++;
	}
}

void Canvas::drawRtlText(const char* text, int x, int y, Color color)
{
	const char* ptr = text;
	while (*ptr) {
		ptr++;
	}

	do {
		ptr--;
		if ((x < _width) && (y < _height) && (x >= 0) && (y >= 0)) {
			_buffer[x + (y * _width)] = *ptr | (color << 8);
		}
		x--;

	} while (text != ptr);
}
