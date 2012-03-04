/******************************************************************************
    rifle.cpp
 ******************************************************************************/
#include "rifle.h"
#include "genericbullet.h"
#include "sound/audioengine.h"


//-----------------------------------------------------------------------------
Rifle::Rifle() :
    Weapon(0.4)
{
    _fireSound = AudioEngine::instance()->createSource(L"rifle.wav");
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
