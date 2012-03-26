/*  basewidget.cpp
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
#include "basewidget.h"
#include "graphics/widgetstack.h"
#include "graphics/images.h"
#include "introwidget.h"
#include "gamewidget.h"


//-----------------------------------------------------------------------------
BaseWidget::BaseWidget(WidgetStack* widgetStack) :
    Widget(widgetStack)
{

    // Add the base widget
    widgetStack->pushWidget(this);

    // Create the intro widget
    _currentWidget = new IntroWidget(widgetStack);
    _currentWidget->addNotificationListener(this);
    widgetStack->pushWidget(_currentWidget);
}


//-----------------------------------------------------------------------------
BaseWidget::~BaseWidget()
{

}


//-----------------------------------------------------------------------------
void BaseWidget::keyEvent(int key, int flags)
{

}


//-----------------------------------------------------------------------------
void BaseWidget::updateEvent()
{

}


//-----------------------------------------------------------------------------
void BaseWidget::paintEvent(Canvas& canvas)
{

}


//-----------------------------------------------------------------------------
void BaseWidget::notification(Notification notification, Widget* sender)
{
    switch (notification) {

        // Close Event
        case N_REQUEST_CLOSE: {

            // Intro widget
            if (IntroWidget* introWidget = dynamic_cast<IntroWidget*>(_currentWidget)) {

                _widgetStack->popWidget(introWidget);
                delete introWidget;

                _currentWidget = new GameWidget(_widgetStack);
                _currentWidget->addNotificationListener(this);
                _widgetStack->pushWidget(_currentWidget);
            }

            // Game Widget
            else if (GameWidget* gameWidget = dynamic_cast<GameWidget*>(_currentWidget)) {

                _widgetStack->popWidget(gameWidget);
                delete gameWidget;

                _currentWidget = new IntroWidget(_widgetStack);
                _currentWidget->addNotificationListener(this);
                _widgetStack->pushWidget(_currentWidget);
            }

        } break;
    }
}
