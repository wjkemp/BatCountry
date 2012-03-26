/*  element.cpp
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
#include "element.h"


//-----------------------------------------------------------------------------
Element::Element() :
    _character(0),
    _color(COLOR_BLACK)
{

}


//-----------------------------------------------------------------------------
Element::Element(const Element& obj) :
    _character(obj._character),
    _color(obj._color)
{

}


//-----------------------------------------------------------------------------
Element::Element(unsigned long character, Color color) :
    _character(character),
    _color(color)
{

}


//-----------------------------------------------------------------------------
Element& Element::operator = (const Element& obj)
{
    if (this != &obj) {
        _character = obj._character;
        _color = obj._color;

    }

    return *this;
}


//-----------------------------------------------------------------------------
Element::~Element()
{

}
