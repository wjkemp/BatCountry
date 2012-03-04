/******************************************************************************
    bitmap.cpp
 ******************************************************************************/
#include "bitmap.h"


//-----------------------------------------------------------------------------
Bitmap::Bitmap(unsigned long* data)
{
    int index = 0;
    _width = data[index++];
    _height = data[index++];

    _buffer = new unsigned long[_width * _height];

    for (int i=0; i < _width * _height; ++i) {
        _buffer[i] = data[index++];
    }
}


//-----------------------------------------------------------------------------
Bitmap::~Bitmap()
{
    delete [] _buffer;
}

