/*  optionswidget.h
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
#ifndef __OPTIONSWIDGET_H__
#define __OPTIONSWIDGET_H__

#include "graphics/widgetstack.h"
#include "graphics/bitmap.h"
#include <vector>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class OptionsWidget : public Widget
{

public:

    enum {
        OptionVolume = 0,
        OptionCount
    };


public:
    OptionsWidget(WidgetStack* widgetStack);
    ~OptionsWidget();

    void setActive();
    void keyEvent(int key, int flags);
    void updateEvent();
    void paintEvent(Canvas& canvas);
    void notification(Notification notification, Widget* sender);


private:
    Bitmap _background;
    bool _active;
    int _index;
    int _volume;
    static const char* _optionStrings[];

};



#endif
