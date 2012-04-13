#ifndef __BITMAPGRAPHICSDEVICE_H__
#define __BITMAPGRAPHICSDEVICE_H__


#include <allegro5/allegro5.h>
#include "graphicsdevice.h"


class BitmapGraphicsDevice : public GraphicsDevice
{
public:
    BitmapGraphicsDevice(int width, int height, bool fullscreen);
    ~BitmapGraphicsDevice();
    void render(Canvas& canvas);
    bool closed();

private:
    int _characterWidth;
    int _characterHeight;
    bool _closed;
    ALLEGRO_DISPLAY* _display;
    ALLEGRO_BITMAP* _font;
    ALLEGRO_COLOR _foregroundColors[16];
    ALLEGRO_EVENT_QUEUE* _eventQueue;
};


#endif
