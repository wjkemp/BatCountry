/*  canvas.h
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
#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "bitmap.h"
#include "element.h"
#include "colors.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
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
