/*  rifle.cpp
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
#include "rifle.h"
#include "genericbullet.h"
#include "sound/audioengine.h"


//-----------------------------------------------------------------------------
Rifle::Rifle() :
    Weapon(0.4)
{
    _fireSound = AudioEngine::instance()->createSource(L"./resources/audio/rifle.wav");
}


//-----------------------------------------------------------------------------
Rifle::~Rifle()
{

}


//-----------------------------------------------------------------------------
std::vector<Bullet*> Rifle::fire(Point position, Direction direction, Rect boundingArea)
{
    std::vector<Bullet*> bullets;

    if (canFire()) {

        switch (direction) {

            case Left: {

                double degrees = 135;
                double radians = -((degrees * 2.0 * 3.141) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 5, 100, boundingArea, Element('\\', COLOR_WHITE)));
            } break;

            case Right: {
                double degrees = 45;
                double radians = -((degrees * 2.0 * 3.141) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 5, 100, boundingArea, Element('/', COLOR_WHITE)));
            } break;

            case Center: {
                double degrees = 90;
                double radians = -((degrees * 2.0 * 3.14159265) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 5, 100, boundingArea, Element('|', COLOR_WHITE)));
            } break;

        }

        _ammunition--;
        _fireSound->play();
        resetCooldownTimer();
    }

    return bullets;
}
