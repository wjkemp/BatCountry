/*  grenade.h
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
#ifndef __GRENADE_H__
#define __GRENADE_H__

#include "bullet.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Grenade : public Bullet
{

public:
    Grenade(
        int x,
        int y,
        double angle,
        double velocity,
        int damage,
        const Rect& activeRect,
        const Element& element);
    ~Grenade();
    void update();


    bool hasRadiusDamage() const { return true; }
    double damageRadius() const { return 10*10; }
    std::list<Particle*> spawnResidue() const;
    
private:
    double _x;
    double _y;
    double _velocityX;
    double _velocityY;
    double _gravity;
    double _velocity;
    double _angle;

};



#endif
