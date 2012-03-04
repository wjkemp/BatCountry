/******************************************************************************
    inputhandler.h
 ******************************************************************************/
#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include <windows.h>



//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class InputHandler
{
public:

    enum Keys
    {
        KEY_UP      = 0x26,
        KEY_DOWN    = 0x28,
        KEY_LEFT    = 0x25,
        KEY_RIGHT   = 0x27,
        KEY_SPACE   = 0x20,
        KEY_ENTER   = 0x0D,
        KEY_ESCAPE  = 0x1B,
        KEY_1       = 0x31,
        KEY_2       = 0x32,
        KEY_3       = 0x33,
        KEY_4       = 0x34,
        KEY_5       = 0x35,
        KEY_6       = 0x36,
        KEY_7       = 0x37,
        KEY_8       = 0x38,
        KEY_9       = 0x39,
        KEY_Z       = 0x5A,
        KEY_X       = 0x58,
        KEY_C       = 0x43
    };

    enum Flags
    {
        fKeyDown    = 0x00000001,
        fKeyUp      = 0x00000002
    };

public:
    InputHandler();
    ~InputHandler();
    void run();
    virtual void keyEvent(int key, int flags) = 0;
    virtual void updateEvent() = 0;

private:
    static const int EVENT_BUFFER_SIZE = 512;
    HANDLE _inputHandle;
    INPUT_RECORD* _eventBuffer;

};



#endif
