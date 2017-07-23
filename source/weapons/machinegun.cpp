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

#include "machinegun.h"
#include "genericbullet.h"
#include "sound/audioengine.h"
#include <math.h>


Machinegun::Machinegun(ModifierManager* modifiers) :
	Weapon(modifiers, 0.1)
{
	_fireSound = AudioEngine::instance()->createSource(L"./resources/audio/machinegun.wav");
}

Machinegun::~Machinegun()
{

}

std::vector<Bullet*> Machinegun::fire(Point position, Direction direction, Rect boundingArea)
{
	std::vector<Bullet*> bullets;
	bool penetrating = _modifiers->isModifierActive(Modifier::mFireBullets);

	if (canFire()) {

		switch (direction) {

			case Left: {

				double degrees = 135;
				double radians = -((degrees * 2.0 * 3.141) / 360.0);
				bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 1, 80, penetrating, boundingArea, Element('.', COLOR_WHITE)));
			} break;

			case Right: {
				double degrees = 45;
				double radians = -((degrees * 2.0 * 3.141) / 360.0);
				bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 1, 80, penetrating, boundingArea, Element('.', COLOR_WHITE)));
			} break;

			case Center: {
				double degrees = 90;
				double radians = -((degrees * 2.0 * 3.14159265) / 360.0);
				bullets.push_back(new GenericBullet(position.x(), position.y(), cos(radians), sin(radians), 1, 80, penetrating, boundingArea, Element('.', COLOR_WHITE)));
			} break;

		}

		if (!_modifiers->isModifierActive(Modifier::mInfiniBullets)) {
			_ammunition--;
		}

		resetCooldownTimer();
		_fireSound->play();
	}

	return bullets;
}
