/*  optionswidget.cpp
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
#include "optionswidget.h"
#include "graphics/widgetstack.h"
#include "graphics/images.h"
#include "sound/audioengine.h"
#include <stdio.h>


//-----------------------------------------------------------------------------
const char* OptionsWidget::_optionStrings[] =
{
    "Volume"
};


//-----------------------------------------------------------------------------
OptionsWidget::OptionsWidget(WidgetStack* widgetStack) :
    Widget(widgetStack),
    _background(IMG_BUY),
    _active(false),
    _index(0),
    _volume(50)
{
}


//-----------------------------------------------------------------------------
OptionsWidget::~OptionsWidget()
{
}


//-----------------------------------------------------------------------------
void OptionsWidget::setActive()
{
    _active = true;
}


//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
void OptionsWidget::updateEvent()
{

}


//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
void OptionsWidget::notification(Notification notification, Widget* sender)
{

}
