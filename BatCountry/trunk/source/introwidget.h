/******************************************************************************
    introwidget.h
 ******************************************************************************/
#ifndef __INTROWIDGET_H__
#define __INTROWIDGET_H__

#include "graphics/widgetstack.h"
#include "graphics/bitmap.h"
#include "utilities/rect.h"
#include "utilities/timer.h"
#include "enemies/enemy.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class IntroWidget : public Widget
{

public:
    IntroWidget(WidgetStack* widgetStack);
    ~IntroWidget();

    void keyEvent(int key, int flags);
    void updateEvent();
    void paintEvent(Canvas& canvas);
    void notification(Notification notification, Widget* sender);

private:
    Rect _enemyArea;
    Bitmap _info;
    Bitmap _overlay;
    Timer _spawnTimer;
    unsigned long _spawnTimeout;
    std::list<Enemy*> _enemies;

};



#endif
