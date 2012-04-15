/******************************************************************************
    basewidget.h
 ******************************************************************************/
#ifndef __BASEWIDGET_H__
#define __BASEWIDGET_H__

#include "graphics/widgetstack.h"
#include "graphics/bitmap.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class BaseWidget : public Widget
{

public:
    BaseWidget(WidgetStack* widgetStack);
    ~BaseWidget();

    void keyEvent(int key, int flags);
    void updateEvent();
    void paintEvent(Canvas& canvas);
    void notification(Notification notification, Widget* sender);

private:
    Widget* _currentWidget;

};



#endif
