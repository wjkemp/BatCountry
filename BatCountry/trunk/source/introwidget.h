/*  introwidget.h
 *
 *  Copyright (C) 2012 Willem Kemp <http://www.thenocturnaltree.com/>
 *  All rights reserved.
 *
 *  This file is part of BatCountry.
 *
 *  BatCountry is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  BatCountry is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with BatCountry. If not, see http://www.gnu.org/licenses/.
 *
 */
#ifndef __INTROWIDGET_H__
#define __INTROWIDGET_H__

#include "graphics/widgetstack.h"
#include "graphics/bitmap.h"
#include "utilities/rect.h"
#include "utilities/timer.h"
#include "enemies/enemy.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class IntroWidget : public Widget
{

public:
    IntroWidget(WidgetStack* widgetStack);
    ~IntroWidget();

    void keyEvent(int key, int flags);
    void updateEvent();
    void paintEvent(Canvas& canvas);
    void notification(Notification notification, Widget* sender);

private:
    Rect _enemyArea;
    Bitmap _info;
    Bitmap _overlay;
    Timer _spawnTimer;
    unsigned long _spawnTimeout;
    std::list<Enemy*> _enemies;

};



#endif
