/******************************************************************************
    widgetstack.cpp
 ******************************************************************************/
#include "widgetstack.h"


//-----------------------------------------------------------------------------
WidgetStack::WidgetStack() :
    _graphicsDevice(80, 25),
    _canvas(80, 25)
{

}


//-----------------------------------------------------------------------------
WidgetStack::~WidgetStack()
{

}


//-----------------------------------------------------------------------------
void WidgetStack::pushWidget(Widget* widget)
{
    _stack.push_back(widget);
}


//-----------------------------------------------------------------------------
void WidgetStack::popWidget(Widget* widget)
{
    _stack.remove(widget);
}


//-----------------------------------------------------------------------------
void WidgetStack::keyEvent(int key, int flags)
{
    Widget* widget(_stack.back());
    if (widget) {
        widget->keyEvent(key, flags);
    }
}


//-----------------------------------------------------------------------------
void WidgetStack::updateEvent()
{

    // Clear the canvas 
    _canvas.clear();


    // Trigger update events
    std::list<Widget*>::const_iterator i;
    for (i = _stack.begin(); i != _stack.end(); ++i) {
        Widget* widget(*i);
        widget->updateEvent();
    }


    // Trigger paint events
    for (i = _stack.begin(); i != _stack.end(); ++i) {
        Widget* widget(*i);
        widget->paintEvent(_canvas);
    }


    // Send notifications
    std::list<Widget*> widgetStackCopy(_stack);
    std::list<Widget*>::iterator j;
    for (j = widgetStackCopy.end(); j != widgetStackCopy.begin();) {

        --j;
        Widget* widget(*j);

        std::list<Widget*> listeners(widget->notificationListeners());
        std::list<Widget::Notification> notifications(widget->notifications());

        std::list<Widget*>::const_iterator l;
        for (l = listeners.begin(); l != listeners.end(); ++l) {
            Widget* listener(*l);
            std::list<Widget::Notification>::const_iterator n;
            for (n = notifications.begin(); n != notifications.end(); ++n) {
                listener->notification(*n, widget);
            }
        }
    }

    _graphicsDevice.render(_canvas);

}
