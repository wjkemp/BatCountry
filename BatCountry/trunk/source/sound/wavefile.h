/******************************************************************************
    wavefile.h
*******************************************************************************/
#ifndef __WAVEFILE_H__
#define __WAVEFILE_H__
#include <windows.h>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class WaveFile
{

public:
    WaveFile();
    ~WaveFile();
    HRESULT open(LPWSTR strFileName);
    HRESULT close();
    HRESULT reset();
    HRESULT read(BYTE* pBuffer, DWORD dwSizeToRead, DWORD* pdwSizeRead);
    DWORD size() const { return _dwSize; }
    WAVEFORMATEX* format() { return _waveFormat; }


protected:
    HRESULT readMMIO();


protected:
    WAVEFORMATEX* _waveFormat;
    HMMIO _hmmio;
    MMCKINFO _ck;
    MMCKINFO _ckRiff;
    DWORD _dwSize;

};

#endif
