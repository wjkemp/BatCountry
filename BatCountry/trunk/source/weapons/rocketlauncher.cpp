/******************************************************************************
    rocketlauncher.cpp
 ******************************************************************************/
#include "rocketlauncher.h"
#include "genericbullet.h"
#include "rocket.h"
#include "sound/audioengine.h"


//-----------------------------------------------------------------------------
RocketLauncher::RocketLauncher() :
    Weapon(0.8)
{
    _fireSound = AudioEngine::instance()->createSource(L"rocketlauncher.wav");
}


//-----------------------------------------------------------------------------
RocketLauncher::~RocketLauncher()
{

}


//-----------------------------------------------------------------------------
std::vector<Bullet*> RocketLauncher::fire(Point position, Direction direction, Rect boundingArea)
{
    std::vector<Bullet*> bullets;

    if (canFire()) {

        switch (direction) {

            case Left: {

                double degrees = 145;
                double radians = -((degrees * 2.0 * 3.141) / 360.0);
                bullets.push_back(new Rocket(position.x(), position.y(), cos(radians), sin(radians), 5, 60, boundingArea, Element('\\', COLOR_WHITE)));
            } break;

            case Right: {
                double degrees = 35;
                double radians = -((degrees * 2.0 * 3.141) / 360.0);
                bullets.push_back(new Rocket(position.x(), position.y(), cos(radians), sin(radians), 5, 60, boundingArea, Element('/', COLOR_WHITE)));
            } break;

            case Center: {
                double degrees = 90;
                double radians = -((degrees * 2.0 * 3.14159265) / 360.0);
                bullets.push_back(new Rocket(position.x(), position.y(), cos(radians), sin(radians), 5, 60, boundingArea, Element('|', COLOR_WHITE)));
            } break;

        }

        _ammunition--;
        _fireSound->play();
        resetCooldownTimer();
    }

    return bullets;
}
