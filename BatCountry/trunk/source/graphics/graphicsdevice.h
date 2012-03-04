/******************************************************************************
    graphicsdevice.h
 ******************************************************************************/
#ifndef __GRAPHICSDEVICE_H__
#define __GRAPHICSDEVICE_H__

#include "canvas.h"
#include <windows.h>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class GraphicsDevice
{

public:
    GraphicsDevice(int width, int height);
    ~GraphicsDevice();
    void render(Canvas& canvas);

private:
    HANDLE _outputHandle;
    CHAR_INFO* _consoleBuffer;
    int _width;
    int _height;

};



#endif
