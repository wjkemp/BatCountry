/*  widgetstack.cpp
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
#include "widgetstack.h"


//-----------------------------------------------------------------------------
WidgetStack::WidgetStack() :
    _graphicsDevice(0),
    _canvas(80, 40),
    _renderTimer("render_timer"),
    _frameRate(0.0),
    _frameCounter(0)
{

}


//-----------------------------------------------------------------------------
WidgetStack::~WidgetStack()
{

}


//-----------------------------------------------------------------------------
void WidgetStack::setGraphicsDevice(GraphicsDevice* graphicsDevice)
{
    _graphicsDevice = graphicsDevice;
}


//-----------------------------------------------------------------------------
void WidgetStack::pushWidget(Widget* widget)
{
    _stack.push_back(widget);
}


//-----------------------------------------------------------------------------
void WidgetStack::popWidget(Widget* widget)
{
    _stack.remove(widget);
}


//-----------------------------------------------------------------------------
void WidgetStack::keyEvent(int key, int flags)
{
    Widget* widget(_stack.back());
    if (widget) {
        widget->keyEvent(key, flags);
    }
}


//-----------------------------------------------------------------------------
bool WidgetStack::closeRequested()
{
    bool result = false;

    if (_graphicsDevice) {
        result = _graphicsDevice->closed();
    }

    return result;
}


//-----------------------------------------------------------------------------
void WidgetStack::updateEvent()
{

    // Clear the canvas 
    _canvas.clear();


    // Trigger update events
    std::list<Widget*>::const_iterator i;
    for (i = _stack.begin(); i != _stack.end(); ++i) {
        Widget* widget(*i);
        widget->updateEvent();
    }


    // Trigger paint events
    for (i = _stack.begin(); i != _stack.end(); ++i) {
        Widget* widget(*i);
        widget->paintEvent(_canvas);
    }


    // Send notifications
    std::list<Widget*> widgetStackCopy(_stack);
    std::list<Widget*>::iterator j;
    for (j = widgetStackCopy.end(); j != widgetStackCopy.begin();) {

        --j;
        Widget* widget(*j);

        std::list<Widget*> listeners(widget->notificationListeners());
        std::list<Widget::Notification> notifications(widget->notifications());

        std::list<Widget*>::const_iterator l;
        for (l = listeners.begin(); l != listeners.end(); ++l) {
            Widget* listener(*l);
            std::list<Widget::Notification>::const_iterator n;
            for (n = notifications.begin(); n != notifications.end(); ++n) {
                listener->notification(*n, widget);
            }
        }
    }


    if (_graphicsDevice) {
        _renderTimer.reset();
        _graphicsDevice->render(_canvas);
        double elapsed = _renderTimer.elapsed();
        _frameRate += (1.0 / elapsed);
        _frameCounter++;

        if (_frameCounter == 100) {
          printf("FPS: %f\n", _frameRate / _frameCounter);
          _frameRate = 0;
          _frameCounter = 0;
        }
    }

}
