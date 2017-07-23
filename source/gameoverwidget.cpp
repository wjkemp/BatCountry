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

#include "gameoverwidget.h"
#include "graphics/widgetstack.h"
#include "graphics/images.h"


GameOverWidget::GameOverWidget(WidgetStack* widgetStack) :
	Widget(widgetStack),
	_info(IMG_INFO)
{
}

GameOverWidget::~GameOverWidget()
{
}

void GameOverWidget::keyEvent(int key, int flags)
{
	if (flags & InputHandler::fKeyDown) {
		if (key == InputHandler::KEY_ENTER) {
			notify(N_REQUEST_CLOSE);
		}
	} else {

	}
}

void GameOverWidget::updateEvent()
{

}

void GameOverWidget::paintEvent(Canvas& canvas)
{
	canvas.drawBitmap(_info, 25, 2);
	canvas.drawText("GAME OVER!", 35, 4, COLOR_LIGHTYELLOW);

	canvas.drawText("Your village has been", 29, 7, COLOR_WHITE);
	canvas.drawText("overrun! Bats have eaten", 28, 8, COLOR_WHITE);
	canvas.drawText("your food, your friends,", 28, 9, COLOR_WHITE);
	canvas.drawText("and your livestock. You", 28, 10, COLOR_WHITE);
	canvas.drawText("are screwed.", 33, 11, COLOR_WHITE);

	canvas.drawText("Press ENTER to continue...", 27, 14, COLOR_WHITE);

}

void GameOverWidget::notification(Notification notification, Widget* sender)
{
}
