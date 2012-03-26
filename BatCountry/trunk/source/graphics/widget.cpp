/*  widget.cpp
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
