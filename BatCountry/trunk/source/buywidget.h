/******************************************************************************
    buywidget.h
 ******************************************************************************/
#ifndef __BUYWIDGET_H__
#define __BUYWIDGET_H__

#include "graphics/widgetstack.h"
#include "graphics/bitmap.h"
#include "weapons/weapon.h"
#include "gamestatistics.h"
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class BuyWidget : public Widget
{

public:
    BuyWidget(WidgetStack* widgetStack, std::vector<Weapon*> weapons, GameStatistics& statistics);
    ~BuyWidget();

    void keyEvent(int key, int flags);
    void updateEvent();
    void paintEvent(Canvas& canvas);
    void notification(Notification notification, Widget* sender);


private:
    std::vector<Weapon*> _weapons;
    GameStatistics& _statistics;
    Bitmap _background;

};



#endif
