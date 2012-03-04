/******************************************************************************
    machinegun.cpp
 ******************************************************************************/
#include "machinegun.h"
#include "genericbullet.h"
#include "sound/audioengine.h"
#include <math.h>


//-----------------------------------------------------------------------------
Machinegun::Machinegun() :
    Weapon(0.1)
{
    _fireSound = AudioEngine::instance()->createSource(L"machinegun.wav");
}


//-----------------------------------------------------------------------------
Machinegun::~Machinegun()
{

}


//-----------------------------------------------------------------------------
std::vector<Bullet*> Machinegun::fire(Point position, Direction direction, Rect boundingArea)
{
    std::vector<Bullet*> bullets;

    if (canFire()) {

        switch (direction) {

            case Left: {

                double degrees = 135;
                double radians = -((degrees * 2.0 * 3.141) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 1, 80, boundingArea, Element('.', COLOR_WHITE)));
            } break;

            case Right: {
                double degrees = 45;
                double radians = -((degrees * 2.0 * 3.141) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 1, 80, boundingArea, Element('.', COLOR_WHITE)));
            } break;

            case Center: {
                double degrees = 90;
                double radians = -((degrees * 2.0 * 3.14159265) / 360.0);
                bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 1, 80, boundingArea, Element('.', COLOR_WHITE)));
            } break;

        }
    
        _ammunition--;
        resetCooldownTimer();
        _fireSound->play();
    }

    return bullets;
}
