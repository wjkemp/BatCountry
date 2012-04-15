/*  widgetstack.h
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
#ifndef __WIDGETSTACK_H__
#define __WIDGETSTACK_H__

#include "graphics/graphicsdevice.h"
#include "graphics/canvas.h"
#include "input/inputhandler.h"
#include "utilities/timer.h"
#include "widget.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
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
