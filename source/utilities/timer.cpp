/*
	Copyright (c) 2017 Willem Kemp (https://github.com/wjkemp)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include "timer.h"
#include <assert.h>


std::list<Timer*>* Timer::_timers = 0;


Timer::Timer(const char* name)
{
	_name = name;
	_time = std::chrono::steady_clock::now();

	_pausedMs = 0;

	if (_timers == 0) {
		_timers = new std::list<Timer*>();
	}

	_timers->push_back(this);
}

Timer::~Timer()
{
	_timers->remove(this);
}

void Timer::reset()
{
	_time = std::chrono::steady_clock::now();
	_pausedMs = 0;
}

double Timer::elapsed() const
{
	auto now = std::chrono::steady_clock::now();
	uint64_t elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - _time).count();
	double elapsed = (((double)elapsedMs + (double)_pausedMs) / 1000.0);
	return elapsed;
}

void Timer::pause()
{
	auto now = std::chrono::steady_clock::now();
	uint64_t elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - _time).count();
	_pausedMs += elapsedMs;
}

void Timer::resume()
{
	_time = std::chrono::steady_clock::now();
}

void Timer::pauseAll()
{
	std::list<Timer*>::iterator i;
	for (i = _timers->begin(); i != _timers->end(); ++i) {
		Timer* timer(*i);
		timer->pause();
	}
}

void Timer::resumeAll()
{
	std::list<Timer*>::iterator i;
	for (i = _timers->begin(); i != _timers->end(); ++i) {
		Timer* timer(*i);
		timer->resume();
	}
}
