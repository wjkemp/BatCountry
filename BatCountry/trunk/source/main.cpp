/*  main.cpp
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
#include <iostream>


//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{

    try {

        WidgetStack widgetStack;
        BaseWidget baseWidget(&widgetStack);
        widgetStack.run();

    } catch (const std::exception& e) {
        std::cout << "Terminated: " << e.what() << std::endl;
    }

    return 0;
}
