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

#include "modifiermanager.h"


ModifierManager::ModifierManager()
{

}

ModifierManager::~ModifierManager()
{

}

void ModifierManager::update()
{
	std::list<ModifierListItem>::const_iterator i = _activeModifiers.begin();
	while (i != _activeModifiers.end()) {
		const ModifierListItem& modifierListItem(*i);
		if (modifierListItem.expired()) {
			i = _activeModifiers.erase(i);
		} else {
			++i;
		}
	}
}

void ModifierManager::addModifier(const Modifier& modifier)
{
	bool exists = false;

	std::list<ModifierListItem>::iterator i;
	for (i = _activeModifiers.begin(); i != _activeModifiers.end(); ++i) {
		ModifierListItem& modifierListItem(*i);
		if (modifierListItem.modifier().id() == modifier.id()) {
			modifierListItem.resetActiveTimer();
			exists = true;
			break;
		}
	}

	if (!exists) {
		_activeModifiers.push_back(modifier);
	}
}

bool ModifierManager::isModifierActive(Modifier::Identifier id) const
{
	bool result = false;

	std::list<ModifierListItem>::const_iterator i;
	for (i = _activeModifiers.begin(); i != _activeModifiers.end(); ++i) {
		const ModifierListItem& modifierListItem(*i);
		if (modifierListItem.modifier().id() == id) {
			result = true;
			break;
		}
	}

	return result;
}

void ModifierManager::drawModifierList(Canvas& canvas)
{
	int index = 0;

	std::list<ModifierListItem>::const_iterator i;
	for (i = _activeModifiers.begin(); i != _activeModifiers.end(); ++i) {
		const ModifierListItem& modifierListItem(*i);
		canvas.drawRtlText(modifierListItem.modifier().getModifierName(), 79, index, COLOR_LIGHTYELLOW);
		index++;
	}
}
