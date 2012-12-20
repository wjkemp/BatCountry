/*  modifierlistitem.h
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
#ifndef __MODIFIERLISTITEM_H__
#define __MODIFIERLISTITEM_H__

#include "utilities/timer.h"
#include "modifier.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class ModifierListItem
{

public:
    ModifierListItem();
    ModifierListItem(const Modifier& modifier);
    ModifierListItem(const ModifierListItem& obj);
    ~ModifierListItem();

    Modifier modifier() const;
    bool expired() const;
    void resetActiveTimer();

private:
    Modifier _modifier;
    Timer _activeTimer;
};



#endif
