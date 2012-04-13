/*  fullscreenhandler.cpp
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
#include "fullscreenhandler.h"


//-----------------------------------------------------------------------------
FullscreenHandler::FullscreenHandler(WidgetStack* widgetStack) :
    _widgetStack(widgetStack),
    _fullscreen(false)
{
    _graphicsDevice = new BitmapGraphicsDevice(80, 40, _fullscreen);
    _widgetStack->setGraphicsDevice(_graphicsDevice);

}


//-----------------------------------------------------------------------------
FullscreenHandler::~FullscreenHandler()
{
}


//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
void FullscreenHandler::updateEvent()
{

}


//-----------------------------------------------------------------------------
bool FullscreenHandler::closeRequested()
{

    return false;
}
