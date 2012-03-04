/******************************************************************************
    element.h
 ******************************************************************************/
#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "colors.h"



//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Element
{

public:
    Element();
    Element(const Element& obj);
    Element(unsigned long character, Color color);
    Element& operator = (const Element& obj);
    ~Element();

    unsigned char character() const { return _character; }
    Color color() const { return _color; }
    unsigned long raw() const { return ((unsigned long)_character | ((unsigned long)_color << 8)); }

private:
    unsigned char _character;
    Color _color;
};



#endif
