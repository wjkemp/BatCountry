/*  audioengine.h
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
#ifndef __AUDIOENGINE_H__
#define __AUDIOENGINE_H__

#include <xaudio2.h>
#include "audiosource.h"
#include <string>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class AudioEngine
{
public:
    static AudioEngine* instance();
    AudioSource* createSource(const std::wstring& filename);
    void setVolume(int volume);

private:
    AudioEngine();

private:
    static AudioEngine* _instance;
    IXAudio2* _engine;
    IXAudio2MasteringVoice* _masteringVoice;

};


#endif