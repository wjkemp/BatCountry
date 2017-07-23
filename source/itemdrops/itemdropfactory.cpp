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

#include "itemdropfactory.h"
#include "utilities/random.h"


struct ItemDropProbability
{
	Modifier::Identifier modifier;
	double probability;
};

static const struct ItemDropProbability itemDropProbabilities[] =
{
	{
		.modifier = Modifier::mNuke,
		.probability = 0.001f
	},
	{
		.modifier = Modifier::mInfiniBullets,
		.probability = 0.008f
	},
	{
		.modifier = Modifier::mFireBullets,
		.probability = 0.012f
	},
	{
		.modifier = Modifier::mBoost,
		.probability = 0.02f
	},
	{
		.modifier = Modifier::MaxModifiers,
		.probability = 0.0f
	}
};

ItemDropFactory::ItemDropFactory()
{

}

ItemDropFactory::~ItemDropFactory()
{

}

ItemDrop* ItemDropFactory::createDrop(int x, int y)
{
	ItemDrop* result = 0;
	double velocity = 0.8;

	int i = 0;
	while (itemDropProbabilities[i].modifier != Modifier::MaxModifiers) {

		if (Random::choice(itemDropProbabilities[i].probability)) {

			Modifier modifier(itemDropProbabilities[i].modifier);
			Element element(modifier.getElement());
			result = new ItemDrop(x, y, Random::randomAngle(90, 70), velocity, modifier, element, Rect(0,0, 80, 34));

			break;

		} else {
			i++;
		}
	}

	return result;
}
