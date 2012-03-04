/******************************************************************************
    element.cpp
 ******************************************************************************/
#include "element.h"


//-----------------------------------------------------------------------------
Element::Element() :
    _character(0),
    _color(COLOR_BLACK)
{

}


//-----------------------------------------------------------------------------
Element::Element(const Element& obj) :
    _character(obj._character),
    _color(obj._color)
{

}


//-----------------------------------------------------------------------------
Element::Element(unsigned long character, Color color) :
    _character(character),
    _color(color)
{

}


//-----------------------------------------------------------------------------
Element& Element::operator = (const Element& obj)
{
    if (this != &obj) {
        _character = obj._character;
        _color = obj._color;

    }

    return *this;
}


//-----------------------------------------------------------------------------
Element::~Element()
{

}
