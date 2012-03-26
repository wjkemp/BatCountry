/*  xaudio2source.h
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
#ifndef __XAUDIO2SOURCE_H__
#define __XAUDIO2SOURCE_H__

#include "audiosource.h"
#include "wavefile.h"
#include <xaudio2.h>
#include <list>
#include <windows.h>


class XAudio2Source;


//-----------------------------------------------------------------------------
class XAudio2SourceVoice : public IXAudio2VoiceCallback
{

public:
    XAudio2SourceVoice(IXAudio2* engine, XAudio2Source* source, WAVEFORMATEX* waveFormat);
    IXAudio2SourceVoice* voice() { return _voice; }
    STDMETHOD_(void, OnVoiceProcessingPassStart)(UINT32 SamplesRequired);
    STDMETHOD_(void, OnStreamEnd)();
    STDMETHOD_(void, OnVoiceProcessingPassEnd)();
    STDMETHOD_(void, OnBufferEnd)(void * pBufferContext);
    STDMETHOD_(void, OnBufferStart)(void * pBufferContext);
    STDMETHOD_(void, OnLoopEnd)(void * pBufferContext);
    STDMETHOD_(void, OnVoiceError)(void * pBufferContext, HRESULT Error);

private:
    XAudio2Source* _source;
    IXAudio2SourceVoice* _voice;

};


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class XAudio2Source : public AudioSource
{
    friend class XAudio2SourceVoice;

public:
    XAudio2Source(IXAudio2* engine, WaveFile* waveFile);
    ~XAudio2Source();
    void play();

protected:
    XAudio2SourceVoice* allocateVoice();
    void recycleVoice(XAudio2SourceVoice* voice);

private:
    IXAudio2* _engine;
    WaveFile* _waveFile;
    BYTE* _waveData;
    unsigned long _size;
    std::list<XAudio2SourceVoice*> _voiceCache;
    CRITICAL_SECTION _lock;
};


#endif
