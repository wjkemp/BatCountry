/*  timer.cpp
 *
 *  Copyright (C) 2012 Willem Kemp <http://www.thenocturnaltree.com/>
 *  All rights reserved.
 *
 *  This file is part of BatCountry.
 *
 *  BatCountry is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  BatCountry is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with BatCountry. If not, see http://www.gnu.org/licenses/.
 *
 */
#include "timer.h"
#include <assert.h>


//-----------------------------------------------------------------------------
std::list<Timer*>* Timer::_timers = 0;



//-----------------------------------------------------------------------------
Timer::Timer(const char* name)
{
    _name = name;
    QueryPerformanceFrequency(&_frequency);
    QueryPerformanceCounter(&_time);

    _pausedMs = 0;
    assert(_time.QuadPart != 0);

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
    assert(_frequency.QuadPart != 0);
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
