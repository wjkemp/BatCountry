/******************************************************************************
    optionswidget.cpp
 ******************************************************************************/
#include "optionswidget.h"
#include "graphics/widgetstack.h"
#include "graphics/images.h"
#include <stdio.h>


//-----------------------------------------------------------------------------
OptionsWidget::OptionsWidget(WidgetStack* widgetStack) :
    Widget(widgetStack),
    _background(IMG_BUY)
{
}


//-----------------------------------------------------------------------------
OptionsWidget::~OptionsWidget()
{
}


//-----------------------------------------------------------------------------
void OptionsWidget::keyEvent(int key, int flags)
{

    if (flags & InputHandler::fKeyDown) {
        notify(N_REQUEST_CLOSE);
    }

}


//-----------------------------------------------------------------------------
void OptionsWidget::updateEvent()
{

}


//-----------------------------------------------------------------------------
void OptionsWidget::paintEvent(Canvas& canvas)
{

    canvas.drawBitmap(_background, 20, 2);
    canvas.drawText("Options", 32, 3, COLOR_LIGHTYELLOW);
    canvas.drawText("Press enter when done", 29, 15, COLOR_WHITE);

}


//-----------------------------------------------------------------------------
void OptionsWidget::notification(Notification notification, Widget* sender)
{

}
