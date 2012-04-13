/*  consoleinputengine.h
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
#ifndef __CONSOLEINPUTENGINE_H__
#define __CONSOLEINPUTENGINE_H__

#include "inputengine.h"
#include <windows.h>



//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class ConsoleInputEngine : public InputEngine
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
    ConsoleInputEngine();
    virtual ~ConsoleInputEngine();
    void run();

private:
    static const int EVENT_BUFFER_SIZE = 512;
    HANDLE _inputHandle;
    INPUT_RECORD* _eventBuffer;

};



#endif
