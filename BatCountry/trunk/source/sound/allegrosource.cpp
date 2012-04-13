/*  allegrosource.cpp
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
#include "allegrosource.h"
#include "allegroengine.h"


//-----------------------------------------------------------------------------
AllegroSource::AllegroSource(AllegroEngine* engine, ALLEGRO_SAMPLE* sample) :
    _engine(engine),
    _sample(sample)
{

}


//-----------------------------------------------------------------------------
AllegroSource::~AllegroSource()
{


}


//-----------------------------------------------------------------------------
void AllegroSource::play()
{
    if (_sample) {
        al_play_sample(_sample, _engine->gain(), 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
}

