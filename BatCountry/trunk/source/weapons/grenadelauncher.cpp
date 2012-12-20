/*  grenadelauncher.cpp
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
#include "grenadelauncher.h"
#include "grenade.h"
#include "genericbullet.h"
#include "sound/audioengine.h"


//-----------------------------------------------------------------------------
GrenadeLauncher::GrenadeLauncher(ModifierManager* modifiers) :
    Weapon(modifiers, 0.6)
{
    _fireSound = AudioEngine::instance()->createSource(L"./resources/audio/grenadelauncher.wav");
}


//-----------------------------------------------------------------------------
GrenadeLauncher::~GrenadeLauncher()
{

}


//-----------------------------------------------------------------------------
std::vector<Bullet*> GrenadeLauncher::fire(Point position, Direction direction, Rect boundingArea)
{
    std::vector<Bullet*> bullets;

    if (canFire()) {

        switch (direction) {

            case Left: {

                double degrees = 145;
                double radians = -((degrees * 2.0 * 3.141) / 360.0);
                bullets.push_back(new Grenade(position.x(), position.y(), radians, 80, 5, boundingArea, Element('*', COLOR_WHITE)));
            } break;

            case Right: {
                double degrees = 35;
                double radians = -((degrees * 2.0 * 3.141) / 360.0);
                bullets.push_back(new Grenade(position.x(), position.y(), radians, 80, 5, boundingArea, Element('*', COLOR_WHITE)));
            } break;

        }

        if (direction != Center) {

            if (!_modifiers->isModifierActive(Modifier::mInfiniBullets)) {
                _ammunition--;
            }

            _fireSound->play();
            resetCooldownTimer();
        }
    }

    return bullets;
}
