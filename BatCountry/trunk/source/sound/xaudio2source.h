/******************************************************************************
    xaudio2source.h
 ******************************************************************************/
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
