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

#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "worldobject.h"
#include "graphics/bitmap.h"
#include "utilities/timer.h"
#include "input/keystate.h"
#include "modifiers/modifiermanager.h"


class Actor : public WorldObject
{
public:
	Actor(ModifierManager* modifiers, const Rect& area, unsigned long& keystate);
	~Actor();

	Rect boundingRect() const;
	void update();
	void render(Canvas& canvas);

private:
	ModifierManager* _modifiers;
	Rect _area;
	Bitmap _image;
	Timer _movementTimer;
	unsigned long& _keystate;

};

#endif
