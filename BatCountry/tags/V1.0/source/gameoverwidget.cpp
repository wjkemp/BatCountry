/*  gameoverwidget.cpp
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
#include "gameoverwidget.h"
#include "graphics/widgetstack.h"
#include "graphics/images.h"



//-----------------------------------------------------------------------------
GameOverWidget::GameOverWidget(WidgetStack* widgetStack) :
    Widget(widgetStack),
    _info(IMG_INFO)
{
}


//-----------------------------------------------------------------------------
GameOverWidget::~GameOverWidget()
{
}


//-----------------------------------------------------------------------------
void GameOverWidget::keyEvent(int key, int flags)
{
    if (flags & InputHandler::fKeyDown) {
        if (key == InputHandler::KEY_ENTER) {
            notify(N_REQUEST_CLOSE);
        }

    } else {

    }

}


//-----------------------------------------------------------------------------
void GameOverWidget::updateEvent()
{

}


//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
void GameOverWidget::notification(Notification notification, Widget* sender)
{
}
