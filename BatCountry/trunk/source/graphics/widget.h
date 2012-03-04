/******************************************************************************
    widget.h
 ******************************************************************************/
#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "canvas.h"
#include <list>
class WidgetStack;


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Widget
{
    friend class WidgetStack;


public:

    enum Notification
    {
        N_REQUEST_CLOSE
    };

public:
    Widget(WidgetStack* widgetStack);
    ~Widget();

    void addNotificationListener(Widget* widget);
    std::list<Widget*> notificationListeners() const;
    std::list<Notification> notifications();

    virtual void keyEvent(int key, int flags) = 0;
    virtual void paintEvent(Canvas& canvas) = 0;
    virtual void updateEvent() = 0;
    virtual void notification(Notification notification, Widget* sender) = 0;


protected:
    void notify(Notification notification);

protected:
    WidgetStack* _widgetStack;
    std::list<Widget*> _notificationListeners;
    std::list<Notification> _notifications;

};


/* 
    Notifications should only be issued during keyEvents, paintEvents, and updateEvents.
    All notifications are queued, and sent asynchronously by the widget stack. This will
    allow the notified widgets to delete other widgets without breaking anything.
*/

#endif
