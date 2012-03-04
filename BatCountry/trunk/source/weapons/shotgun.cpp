/******************************************************************************
    shotgun.cpp
 ******************************************************************************/
#include "shotgun.h"
#include "genericbullet.h"
#include "sound/audioengine.h"
#include <math.h>


//-----------------------------------------------------------------------------
Shotgun::Shotgun() :
    Weapon(0.8)
{
    _fireSound = AudioEngine::instance()->createSource(L"shotgun.wav");
}


//-----------------------------------------------------------------------------
Shotgun::~Shotgun()
{

}


//-----------------------------------------------------------------------------
std::vector<Bullet*> Shotgun::fire(Point position, Direction direction, Rect boundingArea)
{
    std::vector<Bullet*> bullets;

    if (canFire()) {

        switch (direction) {

            case Left: {

                double degrees = 135;
                double radians = -((degrees * 2.0 * 3.14159265) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.1), sin(radians - 0.1), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.1), sin(radians + 0.1), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.2), sin(radians + 0.2), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.2), sin(radians - 0.2), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
            } break;

            case Right: {
                double degrees = 45;
                double radians = -((degrees * 2.0 * 3.14159265) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.1), sin(radians - 0.1), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.1), sin(radians + 0.1), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.2), sin(radians + 0.2), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.2), sin(radians - 0.2), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
            } break;

            case Center: {
                double degrees = 90;
                double radians = -((degrees * 2.0 * 3.14159265) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.2), sin(radians - 0.15), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.2), sin(radians + 0.15), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians + 0.4), sin(radians + 0.25), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians - 0.4), sin(radians - 0.25), 4, 90, boundingArea, Element('.', COLOR_WHITE)));
            } break;

        }

        _ammunition--;
        _fireSound->play();
        resetCooldownTimer();
    }

    return bullets;
}
