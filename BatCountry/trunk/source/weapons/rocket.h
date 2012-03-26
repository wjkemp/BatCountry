/*  rocket.h
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
#ifndef __ROCKET_H__
#define __ROCKET_H__

#include "bullet.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Rocket : public Bullet
{

public:
    Rocket(
        double x,
        double y,
        double directionX,
        double directionY,
        int damage,
        double velocity,
        const Rect& activeRect,
        const Element& element);
    ~Rocket();
    void update();


    bool hasRadiusDamage() const { return true; }
    double damageRadius() const { return 10*10; }
    std::list<Particle*> spawnResidue() const;
    
private:
    double _x;
    double _y;
    double _directionX;
    double _directionY;
    double _velocity;
};



#endif
