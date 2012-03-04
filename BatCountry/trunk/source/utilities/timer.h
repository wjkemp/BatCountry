/******************************************************************************
    timer.h
 ******************************************************************************/
#ifndef __TIMER_H__
#define __TIMER_H__

#include <windows.h>
#include <list>


//-----------------------------------------------------------------------------
//  Class Definition
//-----------------------------------------------------------------------------
class Timer
{

public:
    Timer();
    ~Timer();
    void reset();
    double elapsed() const;
    void pause();
    void resume();

    static void pauseAll();
    static void resumeAll();


private:
    LARGE_INTEGER _time;
    unsigned long _pausedMs;
    LARGE_INTEGER _frequency;
    static std::list<Timer*>* _timers;
    
};



#endif
