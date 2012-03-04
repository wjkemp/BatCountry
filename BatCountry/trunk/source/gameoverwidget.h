/******************************************************************************
    gameoverwidget.h
 ******************************************************************************/
#ifndef __GAMEOVERWIDGET_H__
#define __GAMEOVERWIDGET_H__

#include "graphics/widgetstack.h"
#include "graphics/bitmap.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class GameOverWidget : public Widget
{

public:
    GameOverWidget(WidgetStack* widgetStack);
    ~GameOverWidget();

    void keyEvent(int key, int flags);
    void updateEvent();
    void paintEvent(Canvas& canvas);
    void notification(Notification notification, Widget* sender);

private:
    Bitmap _info;

};



#endif
