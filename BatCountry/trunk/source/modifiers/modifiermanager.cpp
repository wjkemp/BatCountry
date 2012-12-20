/*  modifiermanager.cpp
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
#include "modifiermanager.h"


//-----------------------------------------------------------------------------
ModifierManager::ModifierManager()
{

}


//-----------------------------------------------------------------------------
ModifierManager::~ModifierManager()
{

}


//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
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
