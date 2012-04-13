/*  allegroengine.cpp
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
#include "allegroengine.h"
#include "allegrosource.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


//-----------------------------------------------------------------------------
AllegroEngine::AllegroEngine() :
    _gain(0.5)
{
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(12);
}


//-----------------------------------------------------------------------------
void AllegroEngine::setVolume(int volume)
{
    _gain = (float)volume / 100.0f;
}


//-----------------------------------------------------------------------------
AudioSource* AllegroEngine::createSource(const std::wstring& filename)
{
    std::string tmp;
    tmp.assign(filename.begin(), filename.end());
    ALLEGRO_SAMPLE* sample = al_load_sample(tmp.c_str());
    return new AllegroSource(this, sample);
}
