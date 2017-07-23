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

#include "modifier.h"
#include "utilities/random.h"


Modifier::Modifier() :
	_id(MaxModifiers)
{

}

Modifier::Modifier(Identifier id) :
	_id(id)
{

}

Modifier::Modifier(const Modifier& obj) :
	_id(obj._id)
{

}

Modifier::~Modifier()
{

}

Modifier::Identifier Modifier::id() const
{
	return _id;
}

Element Modifier::getElement() const
{
	switch (_id) {
		case mInfiniBullets: return Element(236, COLOR_LIGHTAQUA);
		case mFireBullets: return Element('!', COLOR_LIGHTYELLOW);
		case mBoost: return Element('+', COLOR_LIGHTGREEN);
		case mNuke: return Element(6, COLOR_LIGHTRED);
		default: return Element('?', COLOR_RED);
	}
}

const char* Modifier::getModifierName() const
{
	switch (_id) {
		case mInfiniBullets: return "InfiniBullets";
		case mFireBullets: return "Fire Bullets";
		case mBoost: return "Boost";
		case mNuke: return "Nuke";
		default: return "?";
	}
}
