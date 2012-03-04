/******************************************************************************
    main.cpp
 ******************************************************************************/
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
