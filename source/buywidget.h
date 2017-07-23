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

#ifndef __BUYWIDGET_H__
#define __BUYWIDGET_H__

#include "graphics/widgetstack.h"
#include "graphics/bitmap.h"
#include "weapons/weapon.h"
#include "gamestatistics.h"
#include <vector>


class BuyWidget : public Widget
{

public:
	BuyWidget(WidgetStack* widgetStack, std::vector<Weapon*> weapons, GameStatistics& statistics);
	~BuyWidget();

	void keyEvent(int key, int flags);
	void updateEvent();
	void paintEvent(Canvas& canvas);
	void notification(Notification notification, Widget* sender);

private:
	std::vector<Weapon*> _weapons;
	GameStatistics& _statistics;
	Bitmap _background;
};

#endif
