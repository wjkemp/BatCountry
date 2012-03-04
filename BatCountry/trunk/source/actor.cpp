/******************************************************************************
    actor.cpp
 ******************************************************************************/
#include "actor.h"
#include "graphics/images.h"
#include "utilities/random.h"


//-----------------------------------------------------------------------------
Actor::Actor(const Rect& area, unsigned long& keystate) :
    WorldObject(40, 18),
    _area(area),
    _image(IMG_ACTOR),
    _keystate(keystate)
{
}


//-----------------------------------------------------------------------------
Actor::~Actor()
{

}



//-----------------------------------------------------------------------------
Rect Actor::boundingRect() const
{
    return Rect::centerAroundPoint(_position, 1, 1);
}


//-----------------------------------------------------------------------------
void Actor::update()
{

    if (_movementTimer.elapsed() > 0.050) {

        if ((_keystate & KEYSTATE_LEFT) && (_position.x() > _area.left())) {
            _position.setX(_position.x() - 1);
        }

        if ((_keystate & KEYSTATE_RIGHT) && (_position.x() < (_area.left() + _area.width() - 1))) {
            _position.setX(_position.x() + 1);
        }

        _movementTimer.reset();
    }
}


//-----------------------------------------------------------------------------
void Actor::render(Canvas& canvas)
{
    Rect rect(Rect::centerAroundPoint(_position, _image.width(), _image.height()));
    canvas.drawBitmap(_image, rect.x(), rect.y());

    
}
