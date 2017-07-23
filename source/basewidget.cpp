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

#include "basewidget.h"
#include "graphics/widgetstack.h"
#include "graphics/images.h"
#include "introwidget.h"
#include "gamewidget.h"


BaseWidget::BaseWidget(WidgetStack* widgetStack) :
	Widget(widgetStack)
{

	// Add the base widget
	widgetStack->pushWidget(this);

	// Create the intro widget
	_currentWidget = new IntroWidget(widgetStack);
	_currentWidget->addNotificationListener(this);
	widgetStack->pushWidget(_currentWidget);
}

BaseWidget::~BaseWidget()
{

}

void BaseWidget::keyEvent(int key, int flags)
{

}

void BaseWidget::updateEvent()
{

}

void BaseWidget::paintEvent(Canvas& canvas)
{

}

void BaseWidget::notification(Notification notification, Widget* sender)
{
	switch (notification) {

		// Close Event
		case N_REQUEST_CLOSE: {

			// Intro widget
			if (IntroWidget* introWidget = dynamic_cast<IntroWidget*>(_currentWidget)) {

				_widgetStack->popWidget(introWidget);
				delete introWidget;

				_currentWidget = new GameWidget(_widgetStack);
				_currentWidget->addNotificationListener(this);
				_widgetStack->pushWidget(_currentWidget);
			}

			// Game Widget
			else if (GameWidget* gameWidget = dynamic_cast<GameWidget*>(_currentWidget)) {

				_widgetStack->popWidget(gameWidget);
				delete gameWidget;

				_currentWidget = new IntroWidget(_widgetStack);
				_currentWidget->addNotificationListener(this);
				_widgetStack->pushWidget(_currentWidget);
			}

		} break;
	}
}
