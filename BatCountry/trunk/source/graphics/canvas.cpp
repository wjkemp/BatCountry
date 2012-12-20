/*  canvas.cpp
 *
 *  Copyright (C) 2012 Willem Kemp <http://www.thenocturnaltree.com/>
 *  All rights reserved.
 *
 *  This file is part of BatCountry.
 *
 *  BatCountry is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  BatCountry is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with BatCountry. If not, see http://www.gnu.org/licenses/.
 *
 */
#include "canvas.h"
#include <string.h>


//-----------------------------------------------------------------------------
Canvas::Canvas(int width, int height) :
    _width(width),
    _height(height)
{
    _buffer = new unsigned long[_width * _height];
}


//-----------------------------------------------------------------------------
Canvas::~Canvas()
{
    delete [] _buffer;
}


//-----------------------------------------------------------------------------
void Canvas::clear()
{
    memset(_buffer, 0, _width * _height * sizeof(unsigned long));
}


//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
void Canvas::drawElement(const Element& element, int x, int y)
{
    unsigned long* dest = _buffer;
    if ((x < _width) && (y < _height) && (x >= 0) && (y >= 0)) {
        dest[x + (y * _width)] = element.raw();
    }
}


//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
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

