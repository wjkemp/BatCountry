/******************************************************************************
    inputhandler.cpp
 ******************************************************************************/
#include "inputhandler.h"



//-----------------------------------------------------------------------------
InputHandler::InputHandler()
{
    _eventBuffer = new INPUT_RECORD[EVENT_BUFFER_SIZE];
    _inputHandle = GetStdHandle(STD_INPUT_HANDLE);

}

//-----------------------------------------------------------------------------
InputHandler::~InputHandler()
{
    delete [] _eventBuffer;
}


//-----------------------------------------------------------------------------
void InputHandler::run()
{
    do {

        // Wait on the input handle
        DWORD waitResult = WaitForSingleObject(_inputHandle, 1);
        switch (waitResult) {

            // Event
            case WAIT_OBJECT_0: {

                DWORD numEvents = 0;
                DWORD numEventsRead = 0;

                GetNumberOfConsoleInputEvents(_inputHandle, &numEvents);
                if (numEvents != 0) {

                    ReadConsoleInput(_inputHandle, _eventBuffer, numEvents, &numEventsRead);

                    for (DWORD i = 0; i < numEventsRead; ++i) {
                        if (_eventBuffer[i].EventType == KEY_EVENT) {
                            int key = _eventBuffer[i].Event.KeyEvent.wVirtualKeyCode;
                            int flags = _eventBuffer[i].Event.KeyEvent.bKeyDown ? fKeyDown : fKeyUp;
                            keyEvent(key, flags);
                        }
                    }
                }

            } break;

            // Timeout
            case WAIT_TIMEOUT: {
                updateEvent();
            } break;
        }

    } while (1);

}
