/******************************************************************************
    widget.cpp
 ******************************************************************************/
#include "widget.h"


//-----------------------------------------------------------------------------
Widget::Widget(WidgetStack* widgetStack) :
    _widgetStack(widgetStack)
{

}


//-----------------------------------------------------------------------------
Widget::~Widget()
{

}


//-----------------------------------------------------------------------------
void Widget::addNotificationListener(Widget* widget)
{
    _notificationListeners.push_back(widget);
}


//-----------------------------------------------------------------------------
std::list<Widget*> Widget::notificationListeners() const
{
    return _notificationListeners;
}


//-----------------------------------------------------------------------------
std::list<Widget::Notification> Widget::notifications()
{
    std::list<Notification> notifications(_notifications);
    _notifications.clear();
    return notifications;
}


//-----------------------------------------------------------------------------
void Widget::notify(Notification notification)
{
    _notifications.push_back(notification);
}
