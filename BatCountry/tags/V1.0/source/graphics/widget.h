/*  widget.h
 *
 *  Copyright (C) 2012 Willem Kemp <http://www.thenocturnaltree.com/>
 *  All rights reserved.
 *
 *  This file is part of BatCountry.
 *
 *  BatCountry is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  BatCountry is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with BatCountry. If not, see http://www.gnu.org/licenses/.
 *
 */
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
    virtual ~Widget();

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
