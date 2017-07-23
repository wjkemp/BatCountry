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

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "bullet.h"
#include "sound/audiosource.h"
#include "modifiers/modifiermanager.h"
#include <string>
#include <vector>


class Weapon
{

public:

	enum Direction
	{
		Left,
		Center,
		Right
	};


public:
	Weapon(ModifierManager* modifiers, double fireCooldownTimeout);
	virtual ~Weapon();
	bool itemIsSold() const { return _itemIsSold; }
	int ammunition() const { return _ammunition; }

	virtual std::string fullName() const = 0;
	virtual std::string shortName() const = 0;
	virtual int itemPrice() const = 0;
	virtual int ammunitionBundlePrice() const = 0;
	virtual int ammunitionBundleSize() const = 0;
	virtual std::vector<Bullet*> fire(Point position, Direction direction, Rect boundingArea) = 0;

	void buyItem();
	void buyAmmunitionBundle();

protected:
	bool canFire() const;
	void resetCooldownTimer();

protected:
	ModifierManager* _modifiers;
	AudioSource* _fireSound;
	bool _itemIsSold;
	int _ammunition;
	double _fireCooldownTimeout;
	Timer _fireCooldownTimer;
};

#endif
