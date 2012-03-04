/******************************************************************************
   actor.h
 ******************************************************************************/
#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "worldobject.h"
#include "graphics/bitmap.h"
#include "utilities/timer.h"
#include "input/keystate.h"



//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Actor : public WorldObject
{

public:
    Actor(const Rect& area, unsigned long& keystate);
    ~Actor();

    Rect boundingRect() const;
    void update();
    void render(Canvas& canvas);

private:
    Rect _area;
    Bitmap _image;
    Timer _movementTimer;
    unsigned long& _keystate;

};



#endif
