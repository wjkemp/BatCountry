/******************************************************************************
    audioengine.h
 ******************************************************************************/
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

private:
    AudioEngine();

private:
    static AudioEngine* _instance;
    IXAudio2* _engine;
};


#endif