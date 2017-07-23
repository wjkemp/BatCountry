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

#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "canvas.h"
#include <list>


class WidgetStack;


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
