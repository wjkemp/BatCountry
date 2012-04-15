/*  allegroinputengine.h
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
#ifndef __ALLEGROINPUTENGINE_H__
#define __ALLEGROINPUTENGINE_H__

#include "inputengine.h"
#include <allegro5/allegro5.h>
#include <map>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class AllegroInputEngine : public InputEngine
{

public:
    AllegroInputEngine();
    virtual ~AllegroInputEngine();
    void run();

private:
    ALLEGRO_EVENT_QUEUE* _eventQueue;
    ALLEGRO_TIMER* _timer;
    std::map<int, int> _keymap;
};



#endif
