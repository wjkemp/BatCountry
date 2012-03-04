/******************************************************************************
    canvas.h
 ******************************************************************************/
#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "bitmap.h"
#include "element.h"
#include "colors.h"


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Canvas
{

public:
    Canvas(int width, int height);
    ~Canvas();
    void clear();
    int width() const   { return _width; }
    int height() const  { return _height; }

    void drawBitmap(const Bitmap& bitmap, int x, int y);
    void drawElement(const Element& element, int x, int y);
    void drawText(const char* text, int x, int y, Color color);

    unsigned long* buffer() { return _buffer; }

private:
    int _width;
    int _height;
    unsigned long* _buffer;

};



#endif
