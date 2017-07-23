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

#include "bullet.h"


Bullet::Bullet(double x, double y, int damage, const Rect& activeRect, const Element& element) :
	WorldObject((int)x, (int)y),
	_x(x),
	_y(y),
	_state(sActive),
	_damage(damage),
	_activeRect(activeRect),
	_element(element),
	_updateTimer("bullet_update_timer")
{

}

Bullet::~Bullet()
{

}

Rect Bullet::boundingRect() const
{
	return Rect::centerAroundPoint(_position, 1, 1);
}

void Bullet::render(Canvas& canvas)
{
	canvas.drawElement(_element, _position.x(), _position.y());
}

bool Bullet::isPenetrating() const
{
	return false;
}

bool Bullet::hasRadiusDamage() const
{
	return false;
}

double Bullet::damageRadius() const
{
	return 0.0;
}

std::list<Particle*> Bullet::spawnResidue() const
{
	return std::list<Particle*>();
}

bool Bullet::intersects(const Rect& rect) const
{
	return false;
}
