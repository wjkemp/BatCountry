/******************************************************************************
    exceptions.h
 ******************************************************************************/
#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <exception>

//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class AudioException : public std::exception
{
public:
    AudioException(const char* what) : std::exception(what) {}
    
};



#endif
