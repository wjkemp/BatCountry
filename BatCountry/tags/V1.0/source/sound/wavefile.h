/*  wavefile.h
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
