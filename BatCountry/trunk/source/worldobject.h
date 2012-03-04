/******************************************************************************
   worldobject.h
 ******************************************************************************/
#ifndef __WORLDOBJECT_H__
#define __WORLDOBJECT_H__

#include "utilities/point.h"
#include "utilities/rect.h"
#include "graphics/canvas.h"
#include <list>



//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class WorldObject
{

public:
    WorldObject(int x, int y);
    ~WorldObject();
    virtual Rect boundingRect() const = 0;
    virtual void update() = 0;
    virtual void render(Canvas& canvas) = 0;

    Point position() const { return _position; }

protected:
    Point _position;

};



#endif
