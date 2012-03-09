/******************************************************************************
    introwidget.cpp
 ******************************************************************************/
#include "introwidget.h"
#include "graphics/widgetstack.h"
#include "graphics/images.h"
#include "enemies/bat.h"
#include "utilities/random.h"


//-----------------------------------------------------------------------------
IntroWidget::IntroWidget(WidgetStack* widgetStack) :
    Widget(widgetStack),
    _enemyArea(-2, 2, 84, 8),
    _spawnTimeout(1000),
    _info(IMG_INFO),
    _overlay(IMG_OVERLAY)
{

}


//-----------------------------------------------------------------------------
IntroWidget::~IntroWidget()
{
    std::list<Enemy*>::const_iterator i;
    for (i = _enemies.begin(); i != _enemies.end(); ++i) {
        Enemy* enemy(*i);
        delete enemy;
    }
}


//-----------------------------------------------------------------------------
void IntroWidget::keyEvent(int key, int flags)
{
    if (flags & InputHandler::fKeyDown) {
        notify(N_REQUEST_CLOSE);

    } else {

    }

}


//-----------------------------------------------------------------------------
void IntroWidget::updateEvent()
{

    // Spawn some background bats
    if ((_spawnTimer.elapsed() * 1000) > _spawnTimeout) {
        
        Bat* bat;
        bat = new Bat(_enemyArea, 5.0);                                  

        _enemies.push_back(bat);
        _spawnTimeout = 1000 + Random::random(500);
        _spawnTimer.reset();
    }


    // Move the bats
    std::list<Enemy*>::const_iterator i = _enemies.begin();
    while (i != _enemies.end()) {
        Enemy* enemy = *i;
        enemy->update();
        if (enemy->state() == Bat::sEscaped) {
            i = _enemies.erase(i);
            delete enemy;
        } else {
            ++i;
        }
    }
}


//-----------------------------------------------------------------------------
void IntroWidget::paintEvent(Canvas& canvas)
{
    // Draw the bats
    std::list<Enemy*>::const_iterator i = _enemies.begin();
    while (i != _enemies.end()) {
        Enemy* enemy = *i;
        enemy->render(canvas);
        ++i;
    }

    canvas.drawBitmap(_overlay, 0, 13);
    canvas.drawBitmap(_info, 25, 2);

    canvas.drawText("We can't stop here,", 30, 3, COLOR_LIGHTYELLOW);
    canvas.drawText("This is Bat Country!", 29, 4, COLOR_LIGHTYELLOW);

    canvas.drawText("Kill the bats before they", 27, 7, COLOR_WHITE);
    canvas.drawText("infest your village. Use", 27, 8, COLOR_WHITE);
    canvas.drawText("the left and right arrows", 27, 9, COLOR_WHITE);
    canvas.drawText("to move, and Z, X and C", 27, 10, COLOR_WHITE);
    canvas.drawText("to fire.", 27, 11, COLOR_WHITE);

    canvas.drawText("Press any key to start...", 27, 14, COLOR_WHITE);
}


//-----------------------------------------------------------------------------
void IntroWidget::notification(Notification notification, Widget* sender)
{
}