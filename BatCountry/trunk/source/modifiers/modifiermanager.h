/*  modifiermanager.h
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
#ifndef __MODIFIERMANAGER_H__
#define __MODIFIERMANAGER_H__

#include "modifierlistitem.h"
#include "graphics/canvas.h"
#include <list>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class ModifierManager
{

public:
    ModifierManager();
    ~ModifierManager();
    void update();
    void addModifier(const Modifier& modifier);
    bool isModifierActive(Modifier::Identifier id) const;
    void drawModifierList(Canvas& canvas);

private:
    std::list<ModifierListItem> _activeModifiers;

};



#endif
