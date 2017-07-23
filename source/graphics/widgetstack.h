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

#ifndef __WIDGETSTACK_H__
#define __WIDGETSTACK_H__

#include "graphics/graphicsdevice.h"
#include "graphics/canvas.h"
#include "input/inputhandler.h"
#include "utilities/timer.h"
#include "widget.h"


class WidgetStack : public InputHandler
{

public:
	WidgetStack();
	~WidgetStack();
	void setGraphicsDevice(GraphicsDevice* graphicsDevice);
	void pushWidget(Widget* widget);
	void popWidget(Widget* widget);

protected:
	void keyEvent(int key, int flags);
	void updateEvent();
	bool closeRequested();

private:
	GraphicsDevice* _graphicsDevice;
	Canvas _canvas;
	std::list<Widget*> _stack;
	Timer _renderTimer;
	double _frameRate;
	int _frameCounter;

};


/*
	The Widget Stack handles three things:
	1. Input. Keyboard events are only passed to the top widget in the stack.
	   Events are processed as they arrive.
	2. Update Events. All widgets are updated, bottom to top.
	3. Paint events. All widgets are painted, bottom to top.
	4. Notifications. All queued notifications are passed to widgets, from top to bottom.
*/

#endif
