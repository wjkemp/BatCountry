/******************************************************************************
    wavefile.cpp
*******************************************************************************/
#include "wavefile.h"
#include <dxerr.h>


//-----------------------------------------------------------------------------
WaveFile::WaveFile() :
    _hmmio(NULL),
    _dwSize(0)
{

}



//-----------------------------------------------------------------------------
WaveFile::~WaveFile()
{
    close();
}


//-----------------------------------------------------------------------------
HRESULT WaveFile::open(LPWSTR filename)
{
    HRESULT hr;

    if (filename == NULL) {
        return E_INVALIDARG;
    }


    // Open the file
    _hmmio = mmioOpen(filename, NULL, MMIO_ALLOCBUF | MMIO_READ);
    if (FAILED(hr = readMMIO())) {
        mmioClose(_hmmio, 0);
        return DXTRACE_ERR(L"ReadMMIO", hr);
    }

    if (FAILED(hr = reset())) {
        return DXTRACE_ERR( L"ResetFile", hr );
    }


    // After the reset, the size of the wav file is m_ck.cksize so store it now
    _dwSize = _ck.cksize;

    return hr;
}


//-----------------------------------------------------------------------------
HRESULT WaveFile::close()
{
    if (_hmmio != NULL) {
        mmioClose(_hmmio, 0);
        _hmmio = NULL;
    }

    return S_OK;
}


//-----------------------------------------------------------------------------
HRESULT WaveFile::reset()
{
    if (_hmmio == NULL) {
        return CO_E_NOTINITIALIZED;
    }

    // Seek to the data
    if (-1 == mmioSeek(_hmmio, _ckRiff.dwDataOffset + sizeof(FOURCC), SEEK_SET)) {
        return DXTRACE_ERR(L"mmioSeek", E_FAIL);
    }

    // Search the input file for the 'data' chunk.
    _ck.ckid = mmioFOURCC('d', 'a', 't', 'a');
    if (0 != mmioDescend(_hmmio, &_ck, &_ckRiff, MMIO_FINDCHUNK)) {
        return DXTRACE_ERR(L"mmioDescend", E_FAIL);
    }

    return S_OK;
}


//-----------------------------------------------------------------------------
HRESULT WaveFile::read(BYTE* pBuffer, DWORD dwSizeToRead, DWORD* pdwSizeRead)
{
    MMIOINFO mmioinfoIn;

    if (_hmmio == NULL) {
        return CO_E_NOTINITIALIZED;
    }

    if (pBuffer == NULL || pdwSizeRead == NULL) {
        return E_INVALIDARG;
    }

    *pdwSizeRead = 0;

    if (0 != mmioGetInfo(_hmmio, &mmioinfoIn, 0)) {
        return DXTRACE_ERR(L"mmioGetInfo", E_FAIL);
    }


    UINT cbDataIn = dwSizeToRead;
    if (cbDataIn > _ck.cksize) {
        cbDataIn = _ck.cksize;
    }


    _ck.cksize -= cbDataIn;

    for (DWORD cT = 0; cT < cbDataIn; cT++) {

        // Copy the bytes from the io to the buffer.
        if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead) {
            if (0 != mmioAdvance(_hmmio, &mmioinfoIn, MMIO_READ)) {
                return DXTRACE_ERR(L"mmioAdvance", E_FAIL);
            }

            if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead) {
                return DXTRACE_ERR(L"mmioinfoIn.pchNext", E_FAIL);
            }
        }

        // Actual copy.
        *(( BYTE*)pBuffer + cT ) = *((BYTE*)mmioinfoIn.pchNext);
        mmioinfoIn.pchNext++;
    }

    if (0 != mmioSetInfo(_hmmio, &mmioinfoIn, 0)) {
        return DXTRACE_ERR(L"mmioSetInfo", E_FAIL);
    }


    *pdwSizeRead = cbDataIn;
    return S_OK;
}


//-----------------------------------------------------------------------------
HRESULT WaveFile::readMMIO()
{
    MMCKINFO ckIn;                  // chunk info. for general use.
    PCMWAVEFORMAT pcmWaveFormat;    // Temp PCM structure to load in.

    memset(&ckIn, 0, sizeof(ckIn));


    if ((0 != mmioDescend(_hmmio, &_ckRiff, NULL, 0))) {
        return DXTRACE_ERR( L"mmioDescend", E_FAIL );
    }


    // Check to make sure this is a valid wave file
    if ((_ckRiff.ckid != FOURCC_RIFF ) ||
        (_ckRiff.fccType != mmioFOURCC( 'W', 'A', 'V', 'E' ))) {
        return DXTRACE_ERR( L"mmioFOURCC", E_FAIL );
    }

    // Search the input file for for the 'fmt ' chunk.
    ckIn.ckid = mmioFOURCC( 'f', 'm', 't', ' ' );
    if (0 != mmioDescend(_hmmio, &ckIn, &_ckRiff, MMIO_FINDCHUNK)) {
        return DXTRACE_ERR(L"mmioDescend", E_FAIL);
    }

    // Expect the 'fmt' chunk to be at least as large as <PCMWAVEFORMAT>;
    // if there are extra parameters at the end, we'll ignore them
    if (ckIn.cksize < ( LONG )sizeof( PCMWAVEFORMAT)) {
        return DXTRACE_ERR(L"sizeof(PCMWAVEFORMAT)", E_FAIL);
    }


    // Read the 'fmt ' chunk into <pcmWaveFormat>.
    if (mmioRead(_hmmio, (HPSTR)&pcmWaveFormat, sizeof(pcmWaveFormat)) != sizeof(pcmWaveFormat)) {
        return DXTRACE_ERR(L"mmioRead", E_FAIL);
    }

    // Allocate the waveformatex, but if its not pcm format, read the next
    // word, and thats how many extra bytes to allocate.
    if (pcmWaveFormat.wf.wFormatTag == WAVE_FORMAT_PCM) {
        _waveFormat = (WAVEFORMATEX*)new CHAR[sizeof(WAVEFORMATEX)];
        if (NULL == _waveFormat) {
            return DXTRACE_ERR( L"m_pwfx", E_FAIL );
        }

        // Copy the bytes from the pcm structure to the waveformatex structure
        memcpy(_waveFormat, &pcmWaveFormat, sizeof(pcmWaveFormat));
        _waveFormat->cbSize = 0;

    } else {

        // Read in length of extra bytes.
        WORD cbExtraBytes = 0L;
        if (mmioRead(_hmmio, (CHAR*)&cbExtraBytes, sizeof(WORD)) != sizeof(WORD)) {
            return DXTRACE_ERR(L"mmioRead", E_FAIL);
        }

        _waveFormat = (WAVEFORMATEX*)new CHAR[sizeof(WAVEFORMATEX) + cbExtraBytes];
        if (NULL == _waveFormat) {
            return DXTRACE_ERR(L"new", E_FAIL);
        }

        // Copy the bytes from the pcm structure to the waveformatex structure
        memcpy(_waveFormat, &pcmWaveFormat, sizeof(pcmWaveFormat));
        _waveFormat->cbSize = cbExtraBytes;

        // Now, read those extra bytes into the structure, if cbExtraAlloc != 0.
        if (mmioRead(_hmmio, (CHAR*)(((BYTE*) & (_waveFormat->cbSize)) + sizeof(WORD)), cbExtraBytes) != cbExtraBytes) {
            delete _waveFormat;
            return DXTRACE_ERR(L"mmioRead", E_FAIL);
        }
    }

    // Ascend the input file out of the 'fmt ' chunk.
    if( 0 != mmioAscend(_hmmio, &ckIn, 0)) {
        delete _waveFormat;
        return DXTRACE_ERR(L"mmioAscend", E_FAIL);
    }


    return S_OK;
}



