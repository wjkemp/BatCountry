/*  bitmap.h
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
#ifndef __BITMAP_H__
#define __BITMAP_H__


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Bitmap
{

public:
    Bitmap(unsigned long* data);
    ~Bitmap();
    int width() const   { return _width; }
    int height() const  { return _height; }
    unsigned long* buffer() const { return _buffer; }

private:
    int _width;
    int _height;
    unsigned long* _buffer;

};



#endif
