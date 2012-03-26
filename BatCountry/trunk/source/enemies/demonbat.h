/*  demonbat.h
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
#ifndef __DEMONBAT_H__
#define __DEMONBAT_H__

#include "enemy.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class DemonBat : public Enemy
{
public:
    enum MovementState
    {
        sMovingLeft,
        sMovingRight
    };

public:
    DemonBat(const Rect& area, double velocityBase);
    ~DemonBat();

    Rect boundingRect() const;
    void update();
    void render(Canvas& canvas);
    std::list<Particle*> spawnParticles();
    int reward() const { return 25; }
    double randomAngle(double initial, double deviation);
    
private:
    Rect _area;
    double _x;
    double _velocityVariation;
    double _velocity;
    MovementState _movementState;
    Bitmap _animationA;
    Bitmap _animationB;
    Bitmap _animationC;
    Timer _animationTimer;
    Timer _movementTimer;
    std::list<Bitmap*> _animation;
    std::list<Bitmap*>::iterator _animationIndex;

};


#endif
