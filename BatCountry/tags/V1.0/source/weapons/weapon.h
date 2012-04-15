/*  weapon.h
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
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "bullet.h"
#include "sound/audiosource.h"
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Weapon
{

public:

    enum Direction
    {
        Left,
        Center,
        Right
    };


public:
    Weapon(double fireCooldownTimeout);
    virtual ~Weapon();
    bool itemIsSold() const { return _itemIsSold; }
    int ammunition() const { return _ammunition; }

    virtual std::string fullName() const = 0;
    virtual std::string shortName() const = 0;
    virtual int itemPrice() const = 0;
    virtual int ammunitionBundlePrice() const = 0;
    virtual int ammunitionBundleSize() const = 0;
    virtual std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea) = 0;

    void buyItem();
    void buyAmmunitionBundle();


protected:
    bool canFire() const;
    void resetCooldownTimer();


protected:
    AudioSource* _fireSound;
    bool _itemIsSold;
    int _ammunition;
    double _fireCooldownTimeout;
    Timer _fireCooldownTimer;

};



#endif
