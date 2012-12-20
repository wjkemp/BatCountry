/*  modifier.cpp
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
#include "modifier.h"


//-----------------------------------------------------------------------------
Modifier::Modifier()
{
    _id = (Identifier)(rand() % MaxModifiers);
}


//-----------------------------------------------------------------------------
Modifier::Modifier(Identifier id) :
    _id(id)
{

}


//-----------------------------------------------------------------------------
Modifier::Modifier(const Modifier& obj) :
    _id(obj._id)
{

}


//-----------------------------------------------------------------------------
Modifier::~Modifier()
{

}


//-----------------------------------------------------------------------------
Modifier::Identifier Modifier::id() const
{
    return _id;
}


//-----------------------------------------------------------------------------
Element Modifier::getElement() const
{
    switch (_id) {
        case mInfiniBullets: return Element(236, COLOR_LIGHTAQUA);
        case mFireBullets: return Element('!', COLOR_LIGHTYELLOW);
        case mBoost: return Element('+', COLOR_LIGHTGREEN);
        case mNuke: return Element(6, COLOR_LIGHTRED);
        default: return Element('?', COLOR_RED);
    }    
}


//-----------------------------------------------------------------------------
const char* Modifier::getModifierName() const
{
    switch (_id) {
        case mInfiniBullets: return "InfiniBullets";
        case mFireBullets: return "Fire Bullets";
        case mBoost: return "Boost";
        case mNuke: return "Nuke";
        default: return "?";
    }        
}
