/*  weapon.cpp
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
#include "weapon.h"


//-----------------------------------------------------------------------------
Weapon::Weapon(ModifierManager* modifiers, double fireCooldownTimeout) :
    _modifiers(modifiers),
    _itemIsSold(false),
    _ammunition(0),
    _fireCooldownTimeout(fireCooldownTimeout),
    _fireCooldownTimer("weapon_fire_cooldown_timer")
{

}


//-----------------------------------------------------------------------------
Weapon::~Weapon()
{

}


//-----------------------------------------------------------------------------
void Weapon::buyItem()
{
    _itemIsSold = true;
    _ammunition += ammunitionBundleSize();
}


//-----------------------------------------------------------------------------
void Weapon::buyAmmunitionBundle()
{
    _ammunition += ammunitionBundleSize();
}


//-----------------------------------------------------------------------------
bool Weapon::canFire() const
{
    double cooldownTimeout = (_modifiers->isModifierActive(Modifier::mBoost) ? _fireCooldownTimeout / 2.0 : _fireCooldownTimeout);
    return (_fireCooldownTimer.elapsed() > cooldownTimeout);
}


//-----------------------------------------------------------------------------
void Weapon::resetCooldownTimer()
{
    _fireCooldownTimer.reset();
}

