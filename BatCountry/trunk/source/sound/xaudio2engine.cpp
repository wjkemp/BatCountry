/*  xaudio2engine.cpp
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
#include "xaudio2engine.h"
#include "xaudio2source.h"
#include "wavefile.h"
#include "utilities/exceptions.h"



//-----------------------------------------------------------------------------
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#endif





//-----------------------------------------------------------------------------
XAudio2Engine::XAudio2Engine()
{
    HRESULT hr;

    _engine = 0;
    CoInitializeEx(NULL, COINIT_MULTITHREADED);


    UINT32 flags = 0;
#ifdef _DEBUG
    flags |= XAUDIO2_DEBUG_ENGINE;
#endif


    // Create the audio engine
    if (FAILED( hr = XAudio2Create(&_engine, flags))) {
        CoUninitialize();
        throw AudioException("AudioEngine: Could not create source engine");
    }


    // Create the mastering voice
    _masteringVoice = NULL;

    if (FAILED( hr = _engine->CreateMasteringVoice(&_masteringVoice))) {
        SAFE_RELEASE(_engine);
        CoUninitialize();
        throw AudioException("AudioEngine: Could not create mastering voice");
    }

    // Set the mastering voice volume
    _masteringVoice->SetVolume(0.5f);
}


//-----------------------------------------------------------------------------
void XAudio2Engine::setVolume(int volume)
{
    // Set the mastering voice volume
    _masteringVoice->SetVolume((double)volume / 100.0);
}


//-----------------------------------------------------------------------------
AudioSource* XAudio2Engine::createSource(const std::wstring& filename)
{
    HRESULT hr;

    // Create a new wave file
    WaveFile* waveFile = new WaveFile();

    if (FAILED(hr = waveFile->open((LPWSTR)filename.c_str()))) {
        throw AudioException("AudioEngine: Could not load WAV file");
    }

    // Return the source
    return new XAudio2Source(_engine, waveFile);
}
