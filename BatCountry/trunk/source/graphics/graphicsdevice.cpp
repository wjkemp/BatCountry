/*  graphicsdevice.cpp
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
#include "graphicsdevice.h"



//-----------------------------------------------------------------------------
GraphicsDevice::GraphicsDevice(int width, int height) :
    _width(width),
    _height(height)
{

    _outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    _consoleBuffer = new CHAR_INFO[_width * _height];

    // Change the window title:
    SetConsoleTitle(TEXT("We can't stop here, this is Bat Country!"));
    SMALL_RECT windowSize = {0, 0, (_width - 1), (_height - 1) };
    COORD bufferSize = {width, height};

    SetConsoleWindowInfo(_outputHandle, TRUE, &windowSize);
    SetConsoleScreenBufferSize(_outputHandle, bufferSize);

    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = 0;
    SetConsoleCursorInfo(_outputHandle, &cursor);

    COORD Position;
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(_outputHandle, Position);

}


//-----------------------------------------------------------------------------
GraphicsDevice::~GraphicsDevice()
{

}


//-----------------------------------------------------------------------------
void GraphicsDevice::render(Canvas& canvas)
{
    COORD charBufSize = { _width, _height };
    COORD characterPos = { 0,0 };
    SMALL_RECT writeArea = { 0, 0, (_width - 1), (_height - 1) }; 

    for (int i=0; i < _width * _height; i++) {
        _consoleBuffer[i].Char.AsciiChar = (canvas.buffer()[i] & 0xFF);
        _consoleBuffer[i].Attributes = ((canvas.buffer()[i] >> 8) & 0xFF);
    }

    WriteConsoleOutputA(_outputHandle, _consoleBuffer, charBufSize, characterPos, &writeArea);
}
