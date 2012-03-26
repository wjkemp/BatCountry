/*  machinegun.h
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
#ifndef __MACHINEGUN_H__
#define __MACHINEGUN_H__

#include "weapon.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Machinegun : public Weapon
{

public:
    Machinegun();
    ~Machinegun();
    std::string fullName() const            { return "Machinegun"; }
    std::string shortName() const           { return "Machinegun"; }
    int itemPrice() const                   { return 200; }
    int ammunitionBundlePrice() const       { return 100; }
    int ammunitionBundleSize() const        { return 50; }
    std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea);

};



#endif
