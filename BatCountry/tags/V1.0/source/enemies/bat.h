/*  bat.h
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
#ifndef __BAT_H__
#define __BAT_H__

#include "enemy.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Bat : public Enemy
{
public:
    enum AnimationState
    {
        sAnimateA,
        sAnimateB
    };

    enum MovementState
    {
        sMovingLeft,
        sMovingRight
    };

public:
    Bat(const Rect& area, double velocityBase);
    ~Bat();

    Rect boundingRect() const;
    void update();
    void render(Canvas& canvas);
    std::list<Particle*> spawnParticles();
    int reward() const { return 10; }
    double randomAngle(double initial, double deviation);
    
private:
    Rect _area;
    double _x;
    double _velocityVariation;
    double _velocity;
    AnimationState _animationState;
    MovementState _movementState;
    Bitmap _animationA;
    Bitmap _animationB;
    Timer _animationTimer;
    Timer _movementTimer;

};



#endif
