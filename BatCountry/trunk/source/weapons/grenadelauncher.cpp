/******************************************************************************
    grenadelauncher.cpp
 ******************************************************************************/
#include "grenadelauncher.h"
#include "grenade.h"
#include "genericbullet.h"
#include "sound/audioengine.h"


//-----------------------------------------------------------------------------
GrenadeLauncher::GrenadeLauncher() :
    Weapon(0.6)
{
    _fireSound = AudioEngine::instance()->createSource(L"grenadelauncher.wav");
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
            _ammunition--;
            _fireSound->play();
            resetCooldownTimer();
        }
    }

    return bullets;
}
