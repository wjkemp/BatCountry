/*  itemdropfactory.cpp
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
#include "itemdropfactory.h"
#include "utilities/random.h"


//-----------------------------------------------------------------------------
ItemDropFactory::ItemDropFactory()
{

}


//-----------------------------------------------------------------------------
ItemDropFactory::~ItemDropFactory()
{

}


//-----------------------------------------------------------------------------
ItemDrop* ItemDropFactory::createDrop(int x, int y)
{
    ItemDrop* result = 0;
    double velocity = 0.8;

    if (Random::choice(0.2)) {

        // Create random modifier
        Modifier modifier;

        // Create element
        Element element(modifier.getElement());

        // Create item drop
        result = new ItemDrop(x, y, Random::randomAngle(90, 70), velocity, modifier, element, Rect(0,0, 80, 34));
    }

    return result;
}
