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

#include "introwidget.h"
#include "graphics/widgetstack.h"
#include "graphics/images.h"
#include "enemies/bat.h"
#include "utilities/random.h"
#include "version.h"


IntroWidget::IntroWidget(WidgetStack* widgetStack) :
	Widget(widgetStack),
	 _enemyArea(-2, 10, 84, 12),
	_spawnTimeout(1000),
	_info(IMG_INFO),
	_overlay(IMG_OVERLAY),
	_spawnTimer("intro_spawn_timer")
{

}

IntroWidget::~IntroWidget()
{
	std::list<Enemy*>::const_iterator i;
	for (i = _enemies.begin(); i != _enemies.end(); ++i) {
		Enemy* enemy(*i);
		delete enemy;
	}
}

void IntroWidget::keyEvent(int key, int flags)
{
	if (flags & InputHandler::fKeyDown) {
		notify(N_REQUEST_CLOSE);

	} else {

	}

}

void IntroWidget::updateEvent()
{

	// Spawn some background bats
	if ((_spawnTimer.elapsed() * 1000) > _spawnTimeout) {

		Bat* bat;
		bat = new Bat(_enemyArea, 5.0);

		_enemies.push_back(bat);
		_spawnTimeout = 1000 + Random::random(500);
		_spawnTimer.reset();
	}


	// Move the bats
	std::list<Enemy*>::const_iterator i = _enemies.begin();
	while (i != _enemies.end()) {
		Enemy* enemy = *i;
		enemy->update();
		if (enemy->state() == Bat::sEscaped) {
			i = _enemies.erase(i);
			delete enemy;
		} else {
			++i;
		}
	}
}

void IntroWidget::paintEvent(Canvas& canvas)
{
	// Draw the bats
	std::list<Enemy*>::const_iterator i = _enemies.begin();
	while (i != _enemies.end()) {
		Enemy* enemy = *i;
		enemy->render(canvas);
		++i;
	}

	canvas.drawBitmap(_overlay, 0, 28);
	canvas.drawBitmap(_info, 25, 8);

	canvas.drawText("We can't stop here,", 30, 9, COLOR_LIGHTYELLOW);
	canvas.drawText("This is Bat Country!", 29, 10, COLOR_LIGHTYELLOW);

	canvas.drawText("Kill the bats before they", 27, 12, COLOR_WHITE);
	canvas.drawText("infest your village. Use", 27, 13, COLOR_WHITE);
	canvas.drawText("the left and right arrows", 27, 14, COLOR_WHITE);
	canvas.drawText("to move, and Z, X and C", 27, 15, COLOR_WHITE);
	canvas.drawText("to fire.", 27, 16, COLOR_WHITE);

	canvas.drawText("Press any key to start...", 27, 20, COLOR_WHITE);

	canvas.drawText("BatCountry " VERSION, 40, 37, COLOR_WHITE);
	canvas.drawText("https://github.com/wjkemp/BatCountry", 40, 38, COLOR_WHITE);
}

void IntroWidget::notification(Notification notification, Widget* sender)
{
}
