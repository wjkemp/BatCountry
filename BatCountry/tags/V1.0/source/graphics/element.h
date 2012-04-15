/*  element.h
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
#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "colors.h"



//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Element
{

public:
    Element();
    Element(const Element& obj);
    Element(unsigned long character, Color color);
    Element& operator = (const Element& obj);
    ~Element();

    unsigned char character() const { return _character; }
    Color color() const { return _color; }
    unsigned long raw() const { return ((unsigned long)_character | ((unsigned long)_color << 8)); }

private:
    unsigned char _character;
    Color _color;
};



#endif
