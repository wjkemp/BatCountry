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

#ifndef __ROCKETLAUNCHER_H__
#define __ROCKETLAUNCHER_H__

#include "weapon.h"
#include <vector>


class RocketLauncher : public Weapon
{

public:
	RocketLauncher(ModifierManager* modifiers);
	~RocketLauncher();
	std::string fullName() const            { return "Rocket Launcher"; }
	std::string shortName() const           { return "Rockets"; }
	int itemPrice() const                   { return 1000; }
	int ammunitionBundlePrice() const       { return 200; }
	int ammunitionBundleSize() const        { return 10; }
	std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea);
};

#endif
