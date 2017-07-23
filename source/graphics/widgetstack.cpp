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

#include "widgetstack.h"


WidgetStack::WidgetStack() :
	_graphicsDevice(0),
	_canvas(80, 40),
	_renderTimer("render_timer"),
	_frameRate(0.0),
	_frameCounter(0)
{

}

WidgetStack::~WidgetStack()
{

}

void WidgetStack::setGraphicsDevice(GraphicsDevice* graphicsDevice)
{
	_graphicsDevice = graphicsDevice;
}

void WidgetStack::pushWidget(Widget* widget)
{
	_stack.push_back(widget);
}

void WidgetStack::popWidget(Widget* widget)
{
	_stack.remove(widget);
}

void WidgetStack::keyEvent(int key, int flags)
{
	Widget* widget(_stack.back());
	if (widget) {
		widget->keyEvent(key, flags);
	}
}

bool WidgetStack::closeRequested()
{
	bool result = false;

	if (_graphicsDevice) {
		result = _graphicsDevice->closed();
	}

	return result;
}

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


	if (_graphicsDevice) {
		_renderTimer.reset();
		_graphicsDevice->render(_canvas);
		double elapsed = _renderTimer.elapsed();
		_frameRate += (1.0 / elapsed);
		_frameCounter++;

		if (_frameCounter == 100) {
		  //printf("FPS: %f\n", _frameRate / _frameCounter);
		  _frameRate = 0;
		  _frameCounter = 0;
		}
	}

}
