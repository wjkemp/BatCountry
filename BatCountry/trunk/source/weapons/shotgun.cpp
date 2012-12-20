/*  shotgun.cpp
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
#include "shotgun.h"
#include "genericbullet.h"
#include "sound/audioengine.h"
#include <math.h>


//-----------------------------------------------------------------------------
Shotgun::Shotgun(ModifierManager* modifiers) :
    Weapon(modifiers, 1.0)
{
    _fireSound = AudioEngine::instance()->createSource(L"./resources/audio/shotgun.wav");
}


//-----------------------------------------------------------------------------
Shotgun::~Shotgun()
{

}


//-----------------------------------------------------------------------------
std::vector<Bullet*> Shotgun::fire(Point position, Direction direction, Rect boundingArea)
{
    std::vector<Bullet*> bullets;
    bool penetrating = _modifiers->isModifierActive(Modifier::mFireBullets);

    if (canFire()) {

        switch (direction) {

            case Left: {

                double degrees = 135;
                double radians = -((degrees * 2.0 * 3.14159265) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.1), sin(radians - 0.1), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.1), sin(radians + 0.1), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.2), sin(radians + 0.2), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.2), sin(radians - 0.2), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
            } break;

            case Right: {
                double degrees = 45;
                double radians = -((degrees * 2.0 * 3.14159265) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.1), sin(radians - 0.1), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.1), sin(radians + 0.1), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.2), sin(radians + 0.2), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.2), sin(radians - 0.2), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
            } break;

            case Center: {
                double degrees = 90;
                double radians = -((degrees * 2.0 * 3.14159265) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.2), sin(radians - 0.15), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.2), sin(radians + 0.15), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.4), sin(radians + 0.25), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.4), sin(radians - 0.25), 4, 90, penetrating, boundingArea, Element('.', COLOR_WHITE)));
            } break;

        }

        if (!_modifiers->isModifierActive(Modifier::mInfiniBullets)) {
            _ammunition--;        
        }

        _fireSound->play();
        resetCooldownTimer();
    }

    return bullets;
}
