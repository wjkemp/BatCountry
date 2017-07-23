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

#ifndef __BULLET_H__
#define __BULLET_H__

#include "worldobject.h"
#include "graphics/element.h"
#include "utilities/timer.h"
#include "particle.h"
#include <list>


class Bullet : public WorldObject
{
public:
	enum State
	{
		sActive,
		sExpired
	};


public:
	Bullet(
		double x,
		double y,
		int damage,
		const Rect& activeRect,
		const Element& element);
	virtual ~Bullet();

	State state() const { return _state; }
	int damage() const { return _damage; }

	Rect boundingRect() const;
	void render(Canvas& canvas);

	virtual bool isPenetrating() const;
	virtual bool hasRadiusDamage() const;
	virtual double damageRadius() const;
	virtual std::list<Particle*> spawnResidue() const;
	virtual bool intersects(const Rect& rect) const;


protected:
	double _x;
	double _y;
	State _state;
	int _damage;
	Rect _activeRect;
	Element _element;
	Timer _updateTimer;
};

#endif
