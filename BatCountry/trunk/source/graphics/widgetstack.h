/******************************************************************************
    widgetstack.h
 ******************************************************************************/
#ifndef __WIDGETSTACK_H__
#define __WIDGETSTACK_H__

#include "graphics/graphicsdevice.h"
#include "graphics/canvas.h"
#include "input/inputhandler.h"
#include "widget.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class WidgetStack : public InputHandler
{

public:
    WidgetStack();
    ~WidgetStack();
    void pushWidget(Widget* widget);
    void popWidget(Widget* widget);

protected:
    void keyEvent(int key, int flags);
    void updateEvent();

private:
    GraphicsDevice _graphicsDevice;
    Canvas _canvas;
    std::list<Widget*> _stack;

};


/*
    The Widget Stack handles three things:
    1. Input. Keyboard events are only passed to the top widget in the stack.
       Events are processed as they arrive.
    2. Update Events. All widgets are updated, bottom to top.
    3. Paint events. All widgets are painted, bottom to top.
    4. Notifications. All queued notifications are passed to widgets, from top to botto.
*/

#endif
