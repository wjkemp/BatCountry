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

#include "modifierlistitem.h"


ModifierListItem::ModifierListItem() :
	_activeTimer("modifier_list_timer")
{

}

ModifierListItem::ModifierListItem(const Modifier& modifier) :
	_modifier(modifier),
	_activeTimer("modifier_list_timer")
{

}

ModifierListItem::ModifierListItem(const ModifierListItem& obj) :
	_modifier(obj._modifier),
	_activeTimer("modifier_list_timer")
{

}

ModifierListItem::~ModifierListItem()
{

}

Modifier ModifierListItem::modifier() const
{
	return _modifier;
}

bool ModifierListItem::expired() const
{
	return (_activeTimer.elapsed() > 10.0);
}

void ModifierListItem::resetActiveTimer()
{
	_activeTimer.reset();
}
