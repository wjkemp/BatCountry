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

#include "optionswidget.h"
#include "graphics/widgetstack.h"
#include "graphics/images.h"
#include "sound/audioengine.h"
#include <stdio.h>


const char* OptionsWidget::_optionStrings[] =
{
	"Volume"
};


OptionsWidget::OptionsWidget(WidgetStack* widgetStack) :
	Widget(widgetStack),
	_background(IMG_BUY),
	_active(false),
	_index(0),
	_volume(50)
{
}

OptionsWidget::~OptionsWidget()
{
}

void OptionsWidget::setActive()
{
	_active = true;
}

void OptionsWidget::keyEvent(int key, int flags)
{

	if (flags & InputHandler::fKeyDown) {
		if (_active) {

			switch (key) {

				case InputHandler::KEY_UP: {
					if (_index == 0) {
						_index = (OptionCount - 1);
					} else {
						_index--;
					}

				} break;

				case InputHandler::KEY_DOWN: {
					if (_index == (OptionCount - 1)) {
						_index = 0;
					} else {
						_index--;
					}
				} break;

				case InputHandler::KEY_LEFT: {
					if (_volume > 0) {
						_volume--;
					}

				} break;

				case InputHandler::KEY_RIGHT: {
					if (_volume < 100) {
						_volume++;
					}
				} break;


				case InputHandler::KEY_ENTER:
				case InputHandler::KEY_ESCAPE: {

					AudioEngine::instance()->setVolume(_volume);

					notify(N_REQUEST_CLOSE);
					_active = false;
				} break;
			}
		}
	}
}

void OptionsWidget::updateEvent()
{

}

void OptionsWidget::paintEvent(Canvas& canvas)
{
	char formatBuffer[128];


	canvas.drawBitmap(_background, 20, 2);
	canvas.drawText("Options", 36, 3, COLOR_LIGHTYELLOW);
	canvas.drawText("Press enter when done", 29, 15, COLOR_WHITE);

	int colMarker = 23;
	int colName = 25;
	int colValue = 50;
	int y = 5;

	for (int i=0; i < OptionCount; ++i) {

		// Marker
		if (i == _index) {
			canvas.drawText("*", colMarker, y, COLOR_WHITE);
		}

		// Name
		canvas.drawText(_optionStrings[i], colName, y, COLOR_WHITE);

		// Value
		switch (i) {
			case OptionVolume: {
				sprintf(formatBuffer, ": %d", _volume);
			} break;
		}

		canvas.drawText(formatBuffer, colValue, y, COLOR_WHITE);

		y++;
	}
}

void OptionsWidget::notification(Notification notification, Widget* sender)
{

}
