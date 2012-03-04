/******************************************************************************
    xaudio2source.cpp
 ******************************************************************************/
#include "xaudio2source.h"



//-----------------------------------------------------------------------------
XAudio2SourceVoice::XAudio2SourceVoice(IXAudio2* engine, XAudio2Source* source, WAVEFORMATEX* waveFormat)
{
    _source = source;
    engine->CreateSourceVoice(&_voice, waveFormat, 0, XAUDIO2_DEFAULT_FREQ_RATIO, this, NULL, NULL);
}


//-----------------------------------------------------------------------------
void XAudio2SourceVoice::OnVoiceProcessingPassStart(UINT32 SamplesRequired)
{

}


//-----------------------------------------------------------------------------
void XAudio2SourceVoice::OnStreamEnd()
{
    _source->recycleVoice(this);
}


//-----------------------------------------------------------------------------
void XAudio2SourceVoice::OnVoiceProcessingPassEnd()
{

}


//-----------------------------------------------------------------------------
void XAudio2SourceVoice::OnBufferEnd(void * pBufferContext)
{

}


//-----------------------------------------------------------------------------
void XAudio2SourceVoice::OnBufferStart(void * pBufferContext)
{

}


//-----------------------------------------------------------------------------
void XAudio2SourceVoice::OnLoopEnd(void * pBufferContext)
{

}


//-----------------------------------------------------------------------------
void XAudio2SourceVoice::OnVoiceError(void * pBufferContext, HRESULT Error)
{

}









//-----------------------------------------------------------------------------
XAudio2Source::XAudio2Source(IXAudio2* engine, WaveFile* waveFile) :
    _engine(engine),
    _waveFile(waveFile)
{
    HRESULT hr;

    // Calculate how many bytes and samples are in the wave
    DWORD cbWaveSize = waveFile->size();
    _size = cbWaveSize;

    // Read the sample data into memory
    _waveData = new BYTE[ cbWaveSize ];

    if( FAILED( hr = waveFile->read(_waveData, cbWaveSize, &cbWaveSize ) ) )
    {
    }


    // Create the Waveform cache
    for (int i=0; i < 10; ++i) {

        // Get format of wave file
        WAVEFORMATEX* pwfx = _waveFile->format();

        // Create the voice
        XAudio2SourceVoice* voice = new XAudio2SourceVoice(engine, this, pwfx);
        _voiceCache.push_back(voice);
    }


    InitializeCriticalSection(&_lock);
}


//-----------------------------------------------------------------------------
XAudio2Source::~XAudio2Source()
{
    DeleteCriticalSection(&_lock);

}


//-----------------------------------------------------------------------------
void XAudio2Source::play()
{

    // Allocate a voice
    XAudio2SourceVoice* voice = allocateVoice();
    if (voice) {

        // Submit the wave sample data using an XAUDIO2_BUFFER structure
        XAUDIO2_BUFFER buffer = {0};
        buffer.pAudioData = _waveData;
        buffer.AudioBytes = _size;
        buffer.Flags = XAUDIO2_END_OF_STREAM;

        voice->voice()->SubmitSourceBuffer(&buffer);
        voice->voice()->Start(0);
    }
    
}



//-----------------------------------------------------------------------------
XAudio2SourceVoice* XAudio2Source::allocateVoice()
{
    XAudio2SourceVoice* voice = 0;
    EnterCriticalSection(&_lock);

    if (_voiceCache.size()) {
        voice = _voiceCache.front();
        _voiceCache.pop_front();
    }

    LeaveCriticalSection(&_lock);

    return voice;
}


//-----------------------------------------------------------------------------
void XAudio2Source::recycleVoice(XAudio2SourceVoice* voice)
{
    EnterCriticalSection(&_lock);
    _voiceCache.push_front(voice);
    LeaveCriticalSection(&_lock);
}
