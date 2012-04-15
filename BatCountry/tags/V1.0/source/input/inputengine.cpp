/*  inputengine.cpp
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
#include "inputengine.h"



//-----------------------------------------------------------------------------
InputEngine::InputEngine()
{

}


//-----------------------------------------------------------------------------
InputEngine::~InputEngine()
{

}


//-----------------------------------------------------------------------------
void InputEngine::addInputHandler(InputHandler* handler)
{
    _inputHandlers.push_back(handler);
}


//-----------------------------------------------------------------------------
void InputEngine::keyEvent(int key, int flags)
{
    std::list<InputHandler*>::const_iterator i;
    for (i = _inputHandlers.begin(); i != _inputHandlers.end(); ++i) {
        InputHandler* handler(*i);
        handler->keyEvent(key, flags);
    }
}


//-----------------------------------------------------------------------------
void InputEngine::updateEvent()
{
    std::list<InputHandler*>::const_iterator i;
    for (i = _inputHandlers.begin(); i != _inputHandlers.end(); ++i) {
        InputHandler* handler(*i);
        handler->updateEvent();
    }
}


//-----------------------------------------------------------------------------
bool InputEngine::closeRequested()
{
    bool result = false;

    std::list<InputHandler*>::const_iterator i;
    for (i = _inputHandlers.begin(); i != _inputHandlers.end(); ++i) {
        InputHandler* handler(*i);
        if (handler->closeRequested()) {
            result = true;
            break;
        }
    }

    return result;
}
