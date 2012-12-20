/*  rocketlauncher.h
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
#ifndef __ROCKETLAUNCHER_H__
#define __ROCKETLAUNCHER_H__

#include "weapon.h"
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class RocketLauncher : public Weapon
{

public:
    RocketLauncher(ModifierManager* modifiers);
    ~RocketLauncher();
    std::string fullName() const            { return "Rocket Launcher"; }
    std::string shortName() const           { return "Rockets"; }
    int itemPrice() const                   { return 1000; }
    int ammunitionBundlePrice() const       { return 200; }
    int ammunitionBundleSize() const        { return 10; }
    std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea);

};



#endif
