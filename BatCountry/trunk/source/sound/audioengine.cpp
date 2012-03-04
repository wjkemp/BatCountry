/******************************************************************************
    audioengine.cpp
 ******************************************************************************/
#include "audioengine.h"
#include "xaudio2source.h"
#include "wavefile.h"
#include "utilities/exceptions.h"



//-----------------------------------------------------------------------------
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#endif


//-----------------------------------------------------------------------------
AudioEngine* AudioEngine::_instance = 0;



//-----------------------------------------------------------------------------
AudioEngine* AudioEngine::instance()
{
    if (_instance == 0) {
        _instance = new AudioEngine();
    }

    return _instance;
}



//-----------------------------------------------------------------------------
AudioEngine::AudioEngine()
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
    IXAudio2MasteringVoice* pMasteringVoice = NULL;

    if (FAILED( hr = _engine->CreateMasteringVoice(&pMasteringVoice))) {
        SAFE_RELEASE(_engine);
        CoUninitialize();
        throw AudioException("AudioEngine: Could not create mastering voice");
    }

    // Set the mastering voice volume
    pMasteringVoice->SetVolume(0.3f);
}


//-----------------------------------------------------------------------------
AudioSource* AudioEngine::createSource(const std::wstring& filename)
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
