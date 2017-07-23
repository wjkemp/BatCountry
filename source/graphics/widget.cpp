/*
	Copyright (c) 2017 Willem Kemp (https://github.com/wjkemp)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include "widget.h"


Widget::Widget(WidgetStack* widgetStack) :
	_widgetStack(widgetStack)
{

}

Widget::~Widget()
{

}

void Widget::addNotificationListener(Widget* widget)
{
	_notificationListeners.push_back(widget);
}

std::list<Widget*> Widget::notificationListeners() const
{
	return _notificationListeners;
}

std::list<Widget::Notification> Widget::notifications()
{
	std::list<Notification> notifications(_notifications);
	_notifications.clear();
	return notifications;
}

void Widget::notify(Notification notification)
{
	_notifications.push_back(notification);
}
