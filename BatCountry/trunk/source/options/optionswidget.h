/******************************************************************************
    optionswidget.h
 ******************************************************************************/
#ifndef __OPTIONSWIDGET_H__
#define __OPTIONSWIDGET_H__

#include "graphics/widgetstack.h"
#include "graphics/bitmap.h"
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class OptionsWidget : public Widget
{

public:
    OptionsWidget(WidgetStack* widgetStack);
    ~OptionsWidget();

    void keyEvent(int key, int flags);
    void updateEvent();
    void paintEvent(Canvas& canvas);
    void notification(Notification notification, Widget* sender);


private:
    Bitmap _background;

};



#endif
