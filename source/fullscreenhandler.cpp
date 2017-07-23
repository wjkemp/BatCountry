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

#include "fullscreenhandler.h"


FullscreenHandler::FullscreenHandler(WidgetStack* widgetStack) :
	_widgetStack(widgetStack),
	_fullscreen(false)
{
	_graphicsDevice = new BitmapGraphicsDevice(80, 40, _fullscreen);
	_widgetStack->setGraphicsDevice(_graphicsDevice);

}

FullscreenHandler::~FullscreenHandler()
{
}

void FullscreenHandler::keyEvent(int key, int flags)
{

	if ((key == InputHandler::KEY_F11) && (flags == InputHandler::fKeyDown)) {
		_widgetStack->setGraphicsDevice(0);
		delete _graphicsDevice;

		_fullscreen = !_fullscreen;

		_graphicsDevice = new BitmapGraphicsDevice(80, 40, _fullscreen);
		_widgetStack->setGraphicsDevice(_graphicsDevice);
	}
}

void FullscreenHandler::updateEvent()
{

}

bool FullscreenHandler::closeRequested()
{
	return false;
}
