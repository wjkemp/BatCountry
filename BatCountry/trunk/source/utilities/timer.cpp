/******************************************************************************
    timer.cpp
 ******************************************************************************/
#include "timer.h"


//-----------------------------------------------------------------------------
std::list<Timer*>* Timer::_timers = 0;



//-----------------------------------------------------------------------------
Timer::Timer()
{
    QueryPerformanceFrequency(&_frequency);
    QueryPerformanceCounter(&_time);
    _pausedMs = 0;

    if (_timers == 0) {
        _timers = new std::list<Timer*>();
    }

    _timers->push_back(this);
}


//-----------------------------------------------------------------------------
Timer::~Timer()
{
    _timers->remove(this);
}


//-----------------------------------------------------------------------------
void Timer::reset()
{
    QueryPerformanceCounter(&_time);
    _pausedMs = 0;
}


//-----------------------------------------------------------------------------
double Timer::elapsed() const
{
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    unsigned long elapsedMs = ((now.QuadPart - _time.QuadPart) * 1000) / _frequency.QuadPart;
    double elapsed = (((double)elapsedMs + (double)_pausedMs) / 1000.0);
    return elapsed;

}


//-----------------------------------------------------------------------------
void Timer::pause()
{
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    _pausedMs += ((now.QuadPart - _time.QuadPart) * 1000) / _frequency.QuadPart;
}


//-----------------------------------------------------------------------------
void Timer::resume()
{
    QueryPerformanceCounter(&_time);
}



//-----------------------------------------------------------------------------
void Timer::pauseAll()
{
    std::list<Timer*>::iterator i;
    for (i = _timers->begin(); i != _timers->end(); ++i) {
        Timer* timer(*i);
        timer->pause();
    }
}


//-----------------------------------------------------------------------------
void Timer::resumeAll()
{
    std::list<Timer*>::iterator i;
    for (i = _timers->begin(); i != _timers->end(); ++i) {
        Timer* timer(*i);
        timer->resume();
    }
}
