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

#ifndef __ITEMDROP_H__
#define __ITEMDROP_H__

#include "worldobject.h"
#include "modifiers/modifier.h"
#include "graphics/element.h"
#include "utilities/timer.h"


class ItemDrop : public WorldObject
{
public:

	enum State
	{
		sDropping,
		sStationary,
		sExpired
	};

public:
	ItemDrop(
		int x,
		int y,
		double angle,
		double velocity,
		const Modifier& modifier,
		const Element& element,
		const Rect& worldRect);
	~ItemDrop();

	Modifier modifier() const;
	Rect boundingRect() const;
	void update();
	void render(Canvas& canvas);
	State state() const { return _state; }

private:
	double _x;
	double _y;
	double _velocityX;
	double _velocityY;
	double _gravity;
	double _velocity;
	double _angle;

	Modifier _modifier;
	Element _element;
	Rect _worldRect;
	State _state;
	Timer _updateTimer;
	Timer _activeTimer;
};

#endif
