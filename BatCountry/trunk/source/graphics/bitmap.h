/******************************************************************************
    bitmap.h
 ******************************************************************************/
#ifndef __BITMAP_H__
#define __BITMAP_H__


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Bitmap
{

public:
    Bitmap(unsigned long* data);
    ~Bitmap();
    int width() const   { return _width; }
    int height() const  { return _height; }
    unsigned long* buffer() const { return _buffer; }

private:
    int _width;
    int _height;
    unsigned long* _buffer;

};



#endif
