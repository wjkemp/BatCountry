/*
	Copyright (c) 2017 Willem Kemp (https://github.com/wjkemp)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__


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
		KEY_C       = 0x43,

		KEY_F11     = 0x7A
	};

	enum Flags
	{
		fKeyDown    = 0x00000001,
		fKeyUp      = 0x00000002
	};

public:
	virtual void keyEvent(int key, int flags) = 0;
	virtual void updateEvent() = 0;
	virtual bool closeRequested() = 0;
};

#endif
